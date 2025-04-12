#ifndef ARCHIVE_H
#define ARCHIVE_H

class Archive {
private:
    int reservationId;
    char dateArchivage[20];

public:
    Archive();
    Archive(int id, const char* date);

    void afficherInfos();
};

#endif
