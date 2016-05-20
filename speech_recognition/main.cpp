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
    
    // set recording time
    int recording_time=3;

    comm.text_to_speech("What is your name?");
    // record audio
    std::string path = comm.capture_audio(recording_time);
    // Sound was recored
    //comm.text_to_speech("Sound was recorded");
    // Play captured sound
    //comm.text_to_speech("Playing the captured sound");
    // play recorded audio
    //comm.play_audio(path);

    // Recognize word from a captured sound
    std::vector<std::string> words = rapp::cloud::speech_detection_sphinx4("/home/nao/ws_rapp_applications_nao/src/rapp-applications-nao/nao/data/mail/sounds/rapp_email.ogg",
        "en",
        {"elephant", "banana","max"},
        {"elephant", "banana","max"},
        {},
        "nao_ogg",
        "rapp",
        "roman",
        "9090",
        true
    );
    comm.text_to_speech("Your name is");
    for (unsigned i=0; i<words.size(); i++)
        comm.text_to_speech(words.at(i));

    comm.text_to_speech("What color do you like?");
    // record audio
    path = comm.capture_audio(recording_time);
    // Recognize word from a captured sound
    words =rapp::cloud::speech_detection_sphinx4("/home/nao/ws_rapp_applications_nao/src/rapp-applications-nao/nao/data/mail/sounds/rapp_email.ogg",
        "en",
        {"red", "blue", "pink", "green"},//{"monday", "tuesday"},
        {"red", "blue", "pink", "green"},
        {},
        "nao_ogg",
        "rapp",
        "roman",
        "9090",
        true
    );

    comm.text_to_speech("You like");
    for (unsigned i=0; i<words.size(); i++)
        comm.text_to_speech(words.at(i));

    return 0;
}
