#ifndef TSOS_NUCLEUS_GDT
#define TSOS_NUCLEUS_GDT

class GlobalDescriptorTable
{
        public:

            class SegmentDescriptor
            {
                private:
                    unsigned short limit_lo;
                    unsigned short base_lo;
                    unsigned char base_hi;
                    unsigned char type;
                    unsigned char limit_hi;
                    unsigned char base_vhi;

                public:
                    SegmentDescriptor(Bakosu::standard::uint32 base, Bakosu::standard::uint32 limit, Bakosu::standard::uint8 type);
                    unsigned int Base();
                    unsigned int Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            unsigned short CodeSegmentSelector();
            unsigned short DataSegmentSelector();
 };

#endif
