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

    struct VDIFile *vdiOpen(char *fn) {
        VDIFile *f;

        f = new VDIFile;
        f->fd = open(fn,O_RDWR);
        read(f->fd,&(f->header),sizeof(f->header));
        f->cursor = 0;

        return f;
    }

    void vdiClose(){
        VDIFile *f;
        close(f->fd);
    }

    off_t vdiSeek(VDIFile *f,off_t offset,int whence){

        off_t location;

        if (whence == SEEK_SET){

            location = offset;

        }
        else if (whence == SEEK_CUR){

            location =  f->cursor + offset;

        }
        else if (whence == SEEK_END){

            location = f->header.disksize + offset;

        }
        else  {

            location = f-> cursor;

        }

        if (location >= 0 && location < f-> header.disksize) {
            f->cursor == location;
        }
        return f->cursor;
    }


    ssize_t vdiRead(VDIFile *f,void *buf,ssize_t n){

        int page, offset, Psize, realpage, realcursor;
        Psize = f->header.Pagesize;
        int cursor = f->cursor;

        page = cursor / Psize;
        offset = cursor % Psize;

        realpage = page;
        realcursor = realpage * Psize + offset;

        lseek(f->fd, realcursor + f->header.OffsetPage, SEEK_SET);
        read(f->fd, buf, n);

        return n;
    }

    ssize_t vdiWrite(VDIFile *f,void *buf,ssize_t n){

        if (n = 0) {
            return 0;
        }
        else if (n > INT_MAX) {
            return -1;
        }
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
  /*      ipb <- blocksize/4

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
*/

    }


    int main() {

    short int magic;
    unsigned int k;

    new VDIFile;
    VDIFile* f;

    vdiOpen("C:\\Users\\User\\Documents\\Term_Project\\fixed-1k.vdi");

    vdiSeek(f,510,SEEK_SET);

    vdiRead(f,&magic,2);
    vdiClose();

    ext2Open("C:\\Users\\User\\Documents\\Term_Project\\fixed-1k.vdi");
    ext2Close();

    FetchBlock();
    FetchFromFile(k);

    return 0;
}
