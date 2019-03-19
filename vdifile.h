#ifndef VDIFILE_H_INCLUDED
#define VDIFILE_H_INCLUDED

      struct VDIHeader {
        unsigned char header[64];
        unsigned long signature;
        int major, minor;
        long int hdr_size;
        long int type;
        long int flags;
        unsigned char description[256];
        unsigned long OffsetPage;
        unsigned long OffsetData;
        long int cylinders;
        long int heads;
        long int sectors;
        long int sectorsize;
        long int unusedPage1;
        off_t disksize;
        long int Pagesize;
        long int PageXsize;
        long int HDDPage;
        long int AllPage;
        unsigned char uuvdi[16];
        unsigned char uusnap[16];
        unsigned char uulink[16];
        unsigned char uuparent[16];
        unsigned char unusedPage2[16];
        unsigned char unusedPage3[40];
    };

    struct VDIFile {
        int fd;

        VDIHeader header;

        off_t cursor;

    };


#endif // VDIFILE_H_INCLUDED
