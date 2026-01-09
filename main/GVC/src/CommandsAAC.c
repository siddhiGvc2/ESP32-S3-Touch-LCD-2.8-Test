#include "defs.h"

void AnalyseAACCommands (char* InputVia,char* pkt) {
    char payload[800];
    int track_id;
    if(strncmp(pkt, "*PLAY:", 6) == 0){
       
        sscanf(pkt, "*PLAY:%d#", &track_id);
        CurrentTrack = track_id;
        PlayCurrentTrack();
    }
    else if(strncmp(pkt, "*PAUSE#", 7) == 0){
        Music_pause();
        SendReply(InputVia, "*PAUSE-OK#");
    }
    else if(strncmp(pkt, "*RESUME#", 8) == 0){
        Music_resume();
        SendReply(InputVia, "*RESUME-OK#");
    }
    else if(strncmp(pkt, "*NEXT#", 6) == 0){
        
        SendReply(InputVia, "*NEXT-OK#");
        CurrentTrack++;

        if(CurrentTrack >= Total_Tracks){
            CurrentTrack = 0;
        }
        PlayCurrentTrack();
    }
    else if(strncmp(pkt, "*PREV#", 6) == 0){
        
        if(CurrentTrack == 0){
            CurrentTrack = Total_Tracks-1;
        }
        else{
            CurrentTrack--;
        }
        PlayCurrentTrack();    
        SendReply(InputVia, "*PREV-OK#");
    }
    else if(strncmp(pkt, "*VOLUME:", 8) == 0){
        int vol;
        sscanf(pkt, "*VOLUME:%d#", &vol);
        if(vol <= Volume_MAX){
            Volume = vol;
            sprintf(payload,"*VOLUME-OK,%d#",vol);
            SendReply(InputVia, payload);
        }
        else{
            SendReply(InputVia, "*VOLUME-ERR#");
        }
    }
   

}