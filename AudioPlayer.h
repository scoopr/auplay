#ifndef EPOXY_AUDIOPLAYER_H
#define EPOXY_AUDIOPLAYER_H




class AudioPlayer {
public:
     
    static AudioPlayer* file(const char* fn);
//    static AudioPlayer* url(const char* url);
    virtual ~AudioPlayer() {}
    
    virtual bool isPlaying() const = 0;
    virtual double duration() const = 0;
    virtual double progress() const = 0;
    virtual void play() = 0;
    
    virtual void seek(double t) = 0 ;


protected:
};



#endif
