#include <iostream>
#include <fstream>
#include <string>

#include <rapp-robots-api/info/info.hpp>
#include <rapp-robots-api/communication/communication.hpp>


int main(int argc, char * argv[]) {
    rapp::robot::info info(argc, argv);
    rapp::robot::communication comm(argc, argv);
    
    comm.text_to_speech("Recording starts in a few moments");

    int recording_time=10;
    
    // record audio
    std::string path = comm.capture_audio(recording_time);

    // Sound was recored
    comm.text_to_speech("Sound was recorded");

    // Play captured sound
    comm.text_to_speech("Playing the captured sound");

    // play recorded audio
    comm.play_audio(path);

    return 0;
}
