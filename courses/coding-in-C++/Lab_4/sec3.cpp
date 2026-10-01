#include <iostream>
#include <string>

class AudioFile
{
public:

    //virutal hat hier gefhelt
    virtual void play() const
    {
        std::cout << "Playing generic audio file\n";
    }

    //abgeleitete Klassen wie B MP§File und WAVFile können diese Methode überschreiben
    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    // 4.Destruktor muss auh virtual sein 
    virtual ~AudioFile()
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string& artist_name)
        : artist(artist_name)
    {
    }

    //1. const hat gefhelt && override hat gefhlt --> notwendig da wir die Methode aus der Basisklasse für unsere Verwendung implementieren
    void play() const override
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    //3. const hat gefehtlt && override hat gefhelt
    void print_info() const override
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    ~MP3File()
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    void play() const override
    {
        std::cout << "Playing WAV file\n";
    }

    void print_info() const override
    {
        std::cout << "Uncompressed WAV file\n";
    }

    ~WAVFile()
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    AudioFile* playlist[2];

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < 2; index++)
    {
        playlist[index]->print_info();
        playlist[index]->play();
    }

    for (int index = 0; index < 2; index++)
    {
        delete playlist[index];
    }

    return 0;
}



/*

Original output:

Generic audio file
Playing generic audio file
Uncompressed WAV file
Playing generic audio file
AudioFile destroyed
AudioFile destroyed



Output after correction: 
MP3 file by Daft Punk
Playing MP3 by Daft Punk
Uncompressed WAV file
Playing WAV file
MP3File destroyed
AudioFile destroyed
WAVFile destroyed
AudioFile destroyed


*/
