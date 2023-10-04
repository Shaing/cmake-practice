#include <iostream>
#include <chrono>
#include <unistd.h>
#include <string>
#include <thread>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int run(string t_name, string input_src, string window_name)
{
	VideoCapture cap(input_src);
    if (!cap.isOpened()) {
        cout << "Cannot open camera\n";
        return 1;
    }

    Mat frame;
    Mat gray;
    int c = 0;
    auto t1 = chrono::high_resolution_clock::now();
    while (true) {
        bool ret = cap.read(frame); // or cap >> frame;
        if (!ret) {
            cout << "Can't receive frame (stream end?). Exiting ...\n";
            break;
        }
        ++c;
        // cvtColor(frame, gray, COLOR_BGR2GRAY);

        imshow(window_name, frame);
        //imshow("live", gray);
        // sleep(1); // for testing FPS 1 sec.

        if (waitKey(1) == 'q') {
            break;
        }
    }
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> fp_ms = t2 - t1;
    cout << "[ " << t_name << "]" << "FPS: " << c / (fp_ms.count() / 1000) << endl;
    cout << "[ " << t_name << "]" << "Totoal frame: " << c << endl;
    return 0;
}

int main(int argc, char** argv)
{
	cout << "Hello World" << endl;
    thread t1{run, "1", "../pexels_videos_2697636 (1080p).mp4", "w1"};
    thread t2{run, "2", "../pexels_videos_2697636 (1080p).mp4", "w2"};
    t1.join();
    t2.join();
	return 0;
}