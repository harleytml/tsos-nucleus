// By Tsuki Superior
#include <generic/fat16.hpp>
#include <generic/nucleus_instance.hpp>

FAT16_quark::FAT16_quark(void)
{
    name = "File Allocation Table 16";
    layout = fat16_layout();
}

bool FAT16_quark::detectsystem(void)
{
    return true;
    uint8_t diskfsname[5];
    tsos->disk.getbytes(0x4f, 0x05, diskfsname);
    const char* fsname = "FAT16";
    for (uint8_t x = 0; x < 0x5; x++) {
        if ((uint8_t)fsname[x] != diskfsname[x]) {
            return false;
        }
    }
}

void FAT16_quark::reset(void) { }

char** FAT16_quark::readdir(char* path) { return nullptr; }

void FAT16_quark::rename(char* path, char* newPath) { }

File FAT16_quark::open(char* path)
{
    File tmp;
    return tmp;
}

void FAT16_quark::close(File file) { }

char* FAT16_quark::read(File file) { return nullptr; }

void FAT16_quark::write(File file, char* data) { }

char* FAT16_quark::readfile(char* path) { return nullptr; }

void FAT16_quark::writefile(char* path, char* data) { }

void FAT16_quark::appendfile(char* path, char* data) { }

bool FAT16_quark::exists(char* path) { return true; }

bool FAT16_quark::isfilenamevalid(char* name)
{
    bool isvalid = false;
    char c;
    uint16_t pos = 0;
    while (name[pos]) {
        c = name[pos];

        // Make sure it is all valid characters
        isvalid = ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '-' || c == '@' || c == '^' || c == '_' || c == '`' || c == '{' || c == '}' || c == '~';

        if (!isvalid) {
            return false;
        }
        pos++;
    }
    return true;
}

bool FAT16_quark::allocatecluster(uint16_t* new_cluster, uint16_t cluster)
{
    uint16_t next_cluster = FIRST_CLUSTER_INDEX_IN_FAT;
    do {
        next_cluster++;
        uint16_t fat_entry;
        tsos->disk.setbytes(movetofatregion(next_cluster), sizeof(fat_entry),
            ((uint8_t*)&fat_entry));

        // Mark it as end of file
        if (fat_entry == 0) {
            fat_entry = 0xffff;
            tsos->disk.setbytes(movetofatregion(next_cluster), sizeof(fat_entry),
                ((uint8_t*)&fat_entry));
            break;
        }
    } while (next_cluster < layout.data_cluster_count - FIRST_CLUSTER_INDEX_IN_FAT);

    if (next_cluster == layout.data_cluster_count) {
        return false;
    }

    // Update current cluster to point to next one
    if (cluster != 0) {
        tsos->disk.setbytes(movetofatregion(cluster), sizeof(next_cluster),
            ((uint8_t*)&next_cluster));
    }

    *new_cluster = next_cluster;
    return true;
}

uint32_t FAT16_quark::movetofatregion(uint16_t cluster)
{
    uint32_t pos = layout.start_fat_region;
    pos += layout.offset;
    pos += cluster * 2;
    seekpoint += pos;
    return pos;
}

int32_t FAT16_quark::getsubdir(char* subdir_name, uint16_t* index, char* path)
{
    const uint16_t beg = *index;
    uint32_t len = 0;

    if (path[beg] != '/') {
        return -1;
    }

    // Skip the root slash
    len++;
    while (path[beg + len] != '\0') {
        if (path[beg + len] == '/') {
            break;
        }

        ++len;
    }

    // Check if path is an intermediate directory
    if (path[beg + len] != '/') {
        return -2;
    }

    if (len > 12) {
        return -1;
    }

    memcpy(subdir_name, path, len);
    subdir_name[len] = '\0';

    *index = beg + len;
    return 0;
}

bool FAT16_quark::isinroot(char* path)
{
    char subdir_name[13];
    uint16_t index = 0;

    return getsubdir(subdir_name, &index, path) < 0;
}

bool FAT16_quark::deleteentryinroot(char* name, bool is_file)
{
    uint16_t entry_index = 0;
    dir_entry entry;

    // Find the entry in the root directory
    if (!findrootdirectoryentry(&entry_index, name)) {
        return false;
    }

    movetorootdirectoryregion(entry_index);
    tsos->disk.getbytes(seekpoint, sizeof(entry), (uint8_t*)&entry);

    // dev.read(&entry, sizeof(entry));
    // Check that we are deleting an entry of the right type
    if (entry.attribute & static_cast<uint8_t>(FILE_ATTRIBUTE::VOLUME)) {
        return -1;
    }
    if ((is_file && (entry.attribute & static_cast<uint8_t>(FILE_ATTRIBUTE::SUBDIR))) || (!is_file && !(entry.attribute & static_cast<uint8_t>(FILE_ATTRIBUTE::SUBDIR)))) {
        return -1;
    }

    markrootentryasavailable(entry_index);
    freeclusterchain(entry.starting_cluster);

    return true;
}

bool FAT16_quark::findrootdirectoryentry(uint16_t* entry_index, char* name)
{
    uint16_t i = 0;

    movetorootdirectoryregion(0);
    for (i = 0; i < bpb.root_entry_count; ++i) {
        dir_entry e;
        // dev.read(&e, sizeof(struct dir_entry));

        // Skip available entry
        if ((uint8_t)(e.name[0]) == AVAILABLE_DIR_ENTRY) {
            continue;
        }

        // Do not allow filename to start with a NULL character
        if (e.name[0] == 0) {
            break;
        }

        // Ignore any VFAT entry
        if ((e.attribute & VFAT_DIR_ENTRY) == VFAT_DIR_ENTRY)
            continue;

        if (memcmp(name, e.name, sizeof(e.name)) == 0) {
            *entry_index = i;
            return true;
        }
    }

    return false;
}

uint32_t FAT16_quark::movetorootdirectoryregion(uint16_t entry_index)
{
    uint32_t pos = layout.start_root_directory_region;
    pos += layout.offset;
    pos += entry_index * 32;
    seekpoint += pos;
    return pos;
}

void FAT16_quark::markrootentryasavailable(uint16_t entry_index)
{
    dir_entry entry;
    memset(&entry, 0, sizeof(entry));

    if (!lastentryinrootdirectory(entry_index)) {
        entry.name[0] = AVAILABLE_DIR_ENTRY;
    }

    movetorootdirectoryregion(entry_index);
    tsos->disk.setbytes(seekpoint, sizeof(entry),
        reinterpret_cast<uint8_t*>(&entry));
}

bool FAT16_quark::lastentryinrootdirectory(uint16_t entry_index)
{
    uint8_t tmp = 0;

    if (entry_index == (bpb.root_entry_count - 1))
        return true;

    /* Check if the next entry is marked as being the end of the
   * root directory list.
   */
    movetorootdirectoryregion(entry_index + 1);
    tsos->disk.getbytes(seekpoint, sizeof(tmp), &tmp);
    return tmp == 0;
}

void FAT16_quark::freeclusterchain(uint16_t cluster)
{
    /*
   * If the file is empty, the starting cluster variable is equal to 0.
   * No need to iterate through the FAT.
   */
    if (cluster == 0) {
        return;
    }

    // Mark all clusters in the FAT as available
    do {
        uint16_t free_cluster = 0;
        uint16_t next_cluster = 0;
        uint32_t pos_cluster = movetofatregion(cluster);
        // dev.read(&next_cluster, sizeof(next_cluster));

        // dev.seek(pos_cluster);
        // dev.write(&free_cluster, sizeof(free_cluster));

        if (next_cluster >= 0xFFF8) {
            break;
        }
        cluster = next_cluster;
    } while (true);
}

uint32_t FAT16_quark::readfromhandle(class entry_handle* handle, void* buffer,
    uint32_t count)
{
    uint32_t bytes_read_count = 0;
    uint8_t* bytes = (uint8_t*)buffer;

    // Check if we reach end of file
    if (handle->remaining_bytes == 0) {
        return 0;
    }

    // Check that cluster is valid
    if (handle->cluster == 0) {
        return 0;
    }

    movetodataregion(handle->cluster, handle->offset);

    // Read in chunk until count is 0 or end of file is reached
    while (count > 0) {
        uint32_t chunk_length = count;
        uint32_t bytes_remaining_in_cluster = 0;

        // Check if we reach end of file
        if (handle->remaining_bytes == 0) {
            return bytes_read_count;
        }

        // Check that we read within the boundary of the current cluster
        bytes_remaining_in_cluster = bpb.sectors_per_cluster * bpb.bytes_per_sector - handle->offset;
        if (chunk_length > bytes_remaining_in_cluster) {
            chunk_length = bytes_remaining_in_cluster;
        }

        // Check that we do not read past the end of file
        if (chunk_length > handle->remaining_bytes) {
            chunk_length = handle->remaining_bytes;
        }

        // bytes[bytes_read_count] = tsos->disk.getbytes(seekpoint, chunk_length);
        handle->remaining_bytes -= chunk_length;
        handle->offset += chunk_length;
        if (handle->offset == bpb.sectors_per_cluster * bpb.bytes_per_sector) {
            handle->offset = 0;

            // Look for the next cluster in the FAT, unless we are already reading the
            // last one
            if (handle->remaining_bytes != 0) {
                uint16_t next_cluster;
                if (getnextcluster(&next_cluster, handle->cluster) < 0)
                    return -1;

                handle->cluster = next_cluster;

                movetodataregion(handle->cluster, handle->offset);
            }
        }
        count -= chunk_length;
        bytes_read_count += chunk_length;
    }

    return bytes_read_count;
}

uint32_t FAT16_quark::getnextcluster(uint16_t* next_cluster, uint16_t cluster)
{
    movetofatregion(cluster);
    (tsos->disk.getbytes(seekpoint, sizeof(cluster),
        reinterpret_cast<uint8_t*>(&next_cluster)));

    return 0;
}

uint32_t FAT16_quark::movetodataregion(uint16_t cluster, uint16_t offset)
{
    uint32_t tmp = cluster - 2;
    uint32_t pos = layout.start_data_region;

    tmp *= bpb.sectors_per_cluster;
    tmp *= bpb.bytes_per_sector;
    pos += layout.offset;
    pos += tmp;
    pos += offset;
    seekpoint += pos;
    return pos;
}