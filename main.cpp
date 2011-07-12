

#include <CoreFoundation/CoreFoundation.h>
#include <iostream>


#include "AudioPlayer.h"








int main() {


    const char *fn = "music.mp3";
    
    AudioPlayer* ap = AudioPlayer::file(fn);

    if(!ap) {
        std::cerr << "Error loading audio" << std::endl;
        return 1;
    }
    
    ap->play();
    
    char indic[] = { '|', '/', '-', '\\' };
    int i = 0;
    do {                                               // 5
//        std::cout << "Loop." << std::endl;
        CFRunLoopRunInMode (                           // 6
            kCFRunLoopDefaultMode,                     // 7
            0.25,                                      // 8
            false                                      // 9
        );
        
        std::cout << "\rPlaying.. " << indic[i];

        double d = ap->progress();
        double min = floor(d/60);
        double sec = floor(fmod(d,60));
        std::cout << "   " << min << ":" << sec;

        d = ap->duration();
        min = floor(d/60);
        sec = floor(fmod(d,60));
        std::cout << "   " << min << ":" << sec;

        std::cout << std::flush;
        
        if(ap->progress() > 5) {
            ap->seek(rand()/(float(RAND_MAX))*ap->duration());
        }
        
        i = (i+1)%4;
    } while (ap->isPlaying());



    delete ap;
    
#if 0    


//    std::cout << "dataformat " << aqData.mDataFormat << std::endl;
    std::cout << "bufferbytesize " << aqData.bufferByteSize << std::endl;
    std::cout << "numpacketstoread " << aqData.mNumPacketsToRead << std::endl;
    std::cout << "maxpacketsz " << maxPacketSize << std::endl;
    std::cout << "df bpp " << aqData.mDataFormat.mBytesPerPacket << std::endl;
    std::cout << "df fpp " << aqData.mDataFormat.mFramesPerPacket << std::endl;



    unsigned int running =0;
    sz = 4;
        status = AudioFileGetProperty (                             // 9
            aqData.mAudioFile,                             // 10
             kAudioQueueProperty_IsRunning ,             // 11
            &running,                                   // 12
            &sz                                    // 13
        );
        
    std::cout << "Running: " << running << std::endl;
    

    

    running =0;
    sz = 4;
        status = AudioFileGetProperty (                             // 9
            aqData.mAudioFile,                             // 10
             kAudioQueueProperty_IsRunning ,             // 11
            &running,                                   // 12
            &sz                                    // 13
        );
        
    std::cout << "Running: " << running << std::endl;


    return 0;
    do {                                               // 5
//        std::cout << "Loop." << std::endl;
        CFRunLoopRunInMode (                           // 6
            kCFRunLoopDefaultMode,                     // 7
            0.25,                                      // 8
            false                                      // 9
        );
    } while (aqData.mIsRunning);
 
    CFRunLoopRunInMode (                               // 10
        kCFRunLoopDefaultMode,
        1,
        false
    );


    std::cout << "Done." << std::endl;
    return 0;
    #endif
}

