#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
     printf("wpa_passphrase is loading...\n");
     printf("\n");

	(void)system("/home/bhogireddi/Desktop/Backup_Data/Home/hostap/wpa_supplicant/wpa_passphrase MTPL-1 MTPL#MTPL#1");
       printf("\n");
	printf("\n");
	printf("wpa_gui is loading\n");
	printf("\n");

	(void)system("/home/bhogireddi/Desktop/Backup_Data/Home/hostap/wpa_supplicant/wpa_gui-qt4/wpa_gui");
     printf("\n");
     printf("\n");
     printf("wpa_supplicant loading\n");
     printf("\n");

	(void)system("/home/bhogireddi/Desktop/Backup_Data/Home/hostap/wpa_supplicant/wpa_supplicant -Dnl80211 -iwlp5s0 -c /home/bhogireddi/hostap/hostap/wpa_supplicant/wpa_supplicant.conf");

 //    (void)system("/home/bhogireddi/Desktop/Backup_Data/Home/hostap/wpa_supplicant/wpa_supplicant -Dnl80211 -iwlx001ea653a7d3 -c /home/bhogireddi/hostap/hostap/wpa_supplicant/wpa_supplicant.conf");
     printf("\n");
     printf("\n");
     printf("wpa_cli loading\n");
     printf("\n");

	(void)system("/home/bhogireddi/Desktop/Backup_Data/Home/hostap/wpa_supplicant/wpa_cli");
}
