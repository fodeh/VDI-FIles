#include <ext2.fs.h>
#include <iostream>
#include <unistd.h>
#include <vdifile.h>
#include <ext2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <typeinfo>

using namespace std;

    //Function thats points to our VDIFile structure and calls an open command
    //Assigns open file to f
    struct VDIFile *vdiOpen(char *fn) {
        VDIFile *f;

        f = new VDIFile;
        f->fd = open(fn,O_RDWR);
        read(f->fd,&(f->header),sizeof(f->header));
        f->cursor = 0;

        return f;
    }

    //Function pointing to our open file and properly closing it once all operations are complete.
    void vdiClose(){
        VDIFile *f;
        close(f->fd);
    }

    //Function for seeking through the file.
    //The offset is a cursor that takes on a position in memory.
    off_t vdiSeek(VDIFile *f,off_t offset,int whence){

        off_t location;

        //If our cursor is at the beginning of the file, move location by the offset
        if (whence == SEEK_SET){

            location = offset;

        }
        
        //If our cursor is moved to the desired location, set new location to where the cursor is plus our offset
        else if (whence == SEEK_CUR){

            location =  f->cursor + offset;

        }
        
        //If our cursor is at the end of the file, move our location according to desired offset and total disk size
        else if (whence == SEEK_END){

            location = f->header.disksize + offset;

        }
        
        //If our cursor is already where we want it, get its location
        else  {

            location = f-> cursor;

        }

        //This does a check on location to ensure our cursor is within the bounded disk space
        if (location >= 0 && location < f-> header.disksize) {
            f->cursor == location;
        }
        
        //We return the position of the cursor
        return f->cursor;
    }

    //Function for reading at the current location
    ssize_t vdiRead(VDIFile *f,void *buf,ssize_t n){

        int page, offset, Psize, realpage, realcursor;
        Psize = f->header.Pagesize;
        int cursor = f->cursor;

        //Determines page and offset from cursor location and overall page size
        page = cursor / Psize;
        offset = cursor % Psize;

        realpage = page;
        realcursor = realpage * Psize + offset;
        
        //Seeks to the beginning of the file, moves to desired location and reads
        lseek(f->fd, realcursor + f->header.OffsetPage, SEEK_SET);
        read(f->fd, buf, n);
        
        //returns read location
        return n;
    }

    //Function for writing to a specific location
    ssize_t vdiWrite(VDIFile *f,void *buf,ssize_t n){

        //If our location is the beginning, we can't write
        if (n = 0) {
            return 0;
        }
        
        //If our location is at the end, we also can't write
        else if (n > INT_MAX) {
            return -1;
        }
        
        //Returns specificed location for writing
        else {
            return n;
        }
}

    struct Ext2fs *ext2Open(char *fn){
        char buf;
        Ext2fs* e;

        vdiOpen(fn);
        vdiSeek(e->f, 446, SEEK_SET);
        vdiRead(e->f, &buf, 16);

        if (buf == 0x83) {
            e->cursor = buf *512;

        }
        else {
            vdiSeek(e->f, 462, SEEK_SET);
            vdiRead(e->f, &buf, 16);}
        if (buf == 0x83){
            e->cursor = buf *512;

        }
        else {
            vdiSeek(e->f, 478, SEEK_SET);
            vdiRead(e->f, &buf, 16);}
        if (buf == 0x83){
            e->cursor = buf *512;

        }
        else {
            vdiSeek(e->f, 494, SEEK_SET);
            vdiRead(e->f, &buf, 16);}
        if (buf == 0x83){
            e->cursor = buf *512;

        }
        vdiSeek(e->f, 1024+e->cursor, SEEK_SET);
        vdiRead(e->f, &buf, e->Mystruct);
        e->sector = buf;

        return e;
    }

    void FetchBlock(){
        Ext2fs* e;
        VDIHeader* h;
        char buf;
        unsigned int blocksize, block;

        vdiSeek(e->f, e->sector, SEEK_SET);

        blocksize = (e->sector * h->Pagesize);

        vdiRead(e->f, &buf, blocksize);

        block = (e->cursor * buf);
    }

    void ext2Close(){
        Ext2fs *e;
        close(e->f->fd);
    }

    void FetchFromFile( unsigned int k){
        ipb <- blocksize/4

        if k < 12 {
            base ← inode.i_block
            goto direct}
        else if k < 12 + ipb {
            base ← inode.i_block + 12
            k ← k − 12
            goto single}
        else if k < 12 + ipb + ipb2 {
            base ← inode.i_block + 13
            k ← k − 12 − ipb
            goto double}
        else{
            base ← inode.i_block + 14
            k ← k − 12 − ipb − ipb2}
        end if


    }


    int main() {

    short int magic;
    unsigned int k;

    new VDIFile;
    VDIFile* f;

    vdiOpen("File location");

    vdiSeek(f,510,SEEK_SET);

    vdiRead(f,&magic,2);
    vdiClose();

    ext2Open("File location");
    ext2Close();

    FetchBlock();
    FetchFromFile(k);

    return 0;
}
