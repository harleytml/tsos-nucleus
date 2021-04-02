#include "generic/memory_table_entry.hpp"

Memory_table_entry::Memory_table_entry() : memory_start((uintptr_t) nullptr)
{
  block_length = sizeof(size_t) * 256;
}

Memory_table_entry::~Memory_table_entry()
{
}