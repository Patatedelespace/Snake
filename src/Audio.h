#include <raylib.h>
#include <string>

class Audio {
private:
    bool playing = false;
    std::string track;
    

public:
    Audio(/* args */);
    ~Audio();

    void play();
    void stop();
    
    void setTrack(std::string track);
    std::string getTrack();

    bool isPlaying();

};

Audio::Audio(/* args */) {

}

Audio::~Audio() {

}
