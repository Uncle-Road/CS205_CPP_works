#include <iostream>
#include <string>

using namespace std;

class Tv {

private:
    int state; // on or off
    int volume; // assumed to be digitized
    int maxchannel; // maximum number of channels
    int channel; // current channel setting
    int mode; // broadcast or cable
    int input; // TV or DVD
public:
    friend class Remote; // Remote can access Tv private parts
    enum {
        Off, On
    };
    enum {
        MinVal, MaxVal = 20
    };
    enum {
        Antenna, Cable
    };
    enum {
        TV, DVD
    };

    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}

    void onoff() { state = (state == On) ? Off : On; }

    bool ison() const { return state == On; }

    bool volup() {
        if (volume < MaxVal) {
            volume++;
            return true;
        } else
            return false;
    };

    bool voldown() {
        if (volume > MinVal) {
            volume--;
            return true;
        } else
            return false;
    };

    void chanup() {
        if (channel < maxchannel)
            channel++;
        else
            channel = 1;
    };

    void chandown() {
        if (channel > 1)
            channel--;
        else
            channel = maxchannel;
    };

    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }

    void set_input() { input = (input == TV) ? DVD : TV; }

    void settings() const {
        cout << "TV is " << (state == Off ? "Off" : "On") << endl;
        if (state == On) {
            cout << "Volume setting = " << volume << endl;
            cout << "Channel setting = " << channel << endl;
            cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
            cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
//            cout<<"After toggling the Remote state:"<<endl;
//            cout<<"The state of Remote is: Interactive\n";
        }
//        else{
//            cout << "The state of Remote is：Normal\n"
//                 <<"The Tv is off, you can not toggle the remote state."<<endl;
//        }
    };


};

class Remote {
private:
    int mode; // controls TV or DVD

public:
    enum {
        normal,interactive
    };

    Remote(int m = Tv::TV) : mode(m) {}

    bool volup(Tv &t) { return t.volup(); }

    bool voldown(Tv &t) { return t.voldown(); }

    void onoff(Tv &t) { t.onoff(); }

    void chanup(Tv &t) { t.chanup(); }

    void chandown(Tv &t) { t.chandown(); }

    void set_chan(Tv &t, int c) { t.channel = c; }//access the private member

    void set_mode(Tv &t) { t.set_mode(); }

    void set_input(Tv &t) { t.set_input(); }

    void display(Tv &t){
        cout << "The state of Remote is " << (t.mode == normal ? "normal" : "interactive") << endl;
        if(t.mode==normal){
            cout<<"The Tv is off, you can not toggle the remote state."<<endl;
        }
    }
};

int main() {
    Tv s42;
    Remote remote;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();//display
    remote.set_mode(s42);
    remote.display(s42);

    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    remote.set_mode(s42);
    remote.display(s42);

    return 0;
}
