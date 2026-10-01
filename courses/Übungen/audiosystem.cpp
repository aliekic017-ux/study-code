#include <iostream>
#include <vector>
#include <string>


class AudioFile
{
    protected:
        int id;
        std::string title;
    
    public:

        AudioFile(int id,const std::string& title)
            :id(id), title(title)
            {

            }

        virtual void play() const = 0;
        virtual ~AudioFile () = default;
};


class MP3File : public AudioFile
{
    private:
        std::string artist;

    public: 
        MP3File(int id, const std::string& title, const std::string& artist)
            :AudioFile(id, title), artist(artist)
            {
                
            }
        virtual void play() const override
        {
            std::cout << "Playing MP3: " << title << "by" << artist << std::endl;
        }
};


class WAVFile : public AudioFile
{
    private: 
        int sampleRate;
    
    public:
        WAVFile(int id, const std::string& title, int sampleRate)
            :AudioFile(id, title), sampleRate(sampleRate)
            {

            }
        virtual void play() const override
        {
            std::cout << "Playing WAV file sample rate" << sampleRate << "Hz" << std::endl;
        }
};


int main ()
{
    MP3File mp31(1, "Around the World", "Daft Punk");
    WAVFile wave1(2, "Drump Loop" , 44100);

    std::vector<AudioFile*> files;

    files.push_back(&mp31);
    files.push_back(&wave1);

    for (AudioFile* AudioFile : files)
    {
        AudioFile->play();
        std::cout << std::endl;

    }
}