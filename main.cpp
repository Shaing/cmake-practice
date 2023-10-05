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
    Mat rframe;
    Mat gray;
    VideoWriter vw;
    vw.open(string{t_name + ".mp4"}.c_str(), VideoWriter::fourcc('m', 'p', '4', 'v'), 30.0, Size(540, 540));
    if (!vw.isOpened())
    {   
        cout << "Can't open VideoWriter. Exiting...\n";
        return -1;
    }

    int c = 0;
    while (true) {
        auto t1 = chrono::high_resolution_clock::now();
        bool ret = cap.read(frame); // or cap >> frame;
        if (!ret) {
            cout << "Can't receive frame (stream end?). Exiting ...\n";
            break;
        }
        ++c;
        // cvtColor(frame, gray, COLOR_BGR2GRAY);
        resize(frame, rframe, Size(540, 540), INTER_LINEAR);


        // imshow(window_name, frame);
        imshow(window_name, rframe);
        //imshow("live", gray);
        // sleep(1); // for testing FPS 1 sec.

        vw.write(rframe);

        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> fp_ms = t2 - t1;
        cout << "[ " << t_name << "]" << "FPS: " << 1 / (fp_ms.count() / 1000) << endl;

        if (waitKey(1) == 'q') {
            break;
        }
    }
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