#include <iostream>
#include <fstream>
#include <string>

#include <rapp-robots-api/info/info.hpp>
#include <rapp-robots-api/communication/communication.hpp>

#include <rapp-cloud-api/upload_file.hpp>
#include <rapp-cloud-api/speech_detection_sphinx4.hpp>


int main(int argc, char * argv[]) {
    rapp::robot::info info(argc, argv);
    rapp::robot::communication comm(argc, argv);
    
    comm.text_to_speech("Recording the sound");
    int recording_time=5;
    // record audio
    std::string path = comm.capture_audio(recording_time);
    // Sound was recored
    comm.text_to_speech("Sound was recored");
    // Play captured sound
    comm.text_to_speech("Playing the captured sound");
    // play recorded audio
    comm.play_audio(path);

    // Recognize word from a captured sound
    rapp::cloud::speech_detection_sphinx4("/home/nao/recordings/microphones/rapp_email.ogg",
        "en",
        {"monday", "tuesday"},
        {"monday", "tuesday"},
        {},
        "nao_ogg",
        "rapp",
        "roman",
        "9090",
        true
    );

    return 0;
}