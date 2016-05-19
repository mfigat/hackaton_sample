#include <iostream>
#include <fstream>
#include <string>

#include <rapp-robots-api/info/info.hpp>
#include <rapp-robots-api/communication/communication.hpp>


int main(int argc, char * argv[]) {
    rapp::robot::info info(argc, argv);
    rapp::robot::communication comm(argc, argv);
    
    comm.text_to_speech("Recording the sound will start in 3 seconds");
    comm.text_to_speech("2");
    comm.text_to_speech("1");

    int recording_time=10;
    
    // record audio
    string file_path=comm.capture_audio(recording_time);

    // Sound was recored
    comm.text_to_speech("Sound was recored");

    // Play captured sound
    comm.text_to_speech("Playing the captured sound");

    // play recorded audio
    comm.play_audio(info.get_path(file_path));

    return 0;
}
