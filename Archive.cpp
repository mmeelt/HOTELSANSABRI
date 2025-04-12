#include "Archive.h"
#include <stdio.h>
#include <string.h>

Archive::Archive() : reservationId(0) {
    strcpy(dateArchivage, "01/01/2000");
}

Archive::Archive(int id, const char* date)
    : reservationId(id) {
    strncpy(dateArchivage, date, sizeof(dateArchivage) - 1);
    dateArchivage[sizeof(dateArchivage) - 1] = '\0';
}

void Archive::afficherInfos() {
    printf("Archive - ID Réservation: %d, Date d'archivage: %s\n", reservationId, dateArchivage);
}
