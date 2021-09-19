#include <bangtal>// ��Ż ���̺귯���� ����ϱ� ���� ��� ����
#include <time.h>
#include <stdlib.h>
using namespace bangtal;      // bangtal ���� �����̽��� ��� ����






int main()
{
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    auto first = Scene::create("PUZZLE GAME", "Images-2/first.png");
    auto scene = Scene::create("PUZZLE GAME", "Images-2/first.png");



    //���� �ʱ� ���� (���� �׸� ��ġ)
    auto p1 = Object::create("Images-2/p1.png", scene, 275, 540);
    auto p2 = Object::create("Images-2/p2.png", scene, 455, 540);
    auto p3 = Object::create("Images-2/p3.png", scene, 635, 540);
    auto p4 = Object::create("Images-2/p4.png", scene, 815, 540);   // p4 = blank �̹���

    auto p5 = Object::create("Images-2/p5.png", scene, 275, 360);
    auto p6 = Object::create("Images-2/p6.png", scene, 455, 360);
    auto p7 = Object::create("Images-2/p7.png", scene, 635, 360);
    auto p8 = Object::create("Images-2/p8.png", scene, 815, 360);

    auto p9 = Object::create("Images-2/p9.png", scene, 275, 180);
    auto p10 = Object::create("Images-2/p10.png", scene, 455, 180);
    auto p11 = Object::create("Images-2/p11.png", scene, 635, 180);
    auto p12 = Object::create("Images-2/p12.png", scene, 815, 180);

    auto p13 = Object::create("Images-2/p13.png", scene, 275, 0);
    auto p14 = Object::create("Images-2/p14.png", scene, 455, 0);
    auto p15 = Object::create("Images-2/p15.png", scene, 635, 0);
    auto p16 = Object::create("Images-2/p16.png", scene, 815, 0);


    //�� ���� ��ġ�� �迭
    int arr[16][2] = { {275,540}, {455,540}, {635,540}, {815,540}, {275, 360}, {455,360}, {635, 360}, {815, 360}, {275, 180}, {455, 180}, {635, 180}, {815, 180}, {275, 0}, {455, 0}, {635, 0}, {815, 0} };


    //���۹�ư, �������ư, Ÿ�̸� ����
    auto playButton = Object::create("Images-2/����.png", first, 470, 100);
    auto endButton = Object::create("Images-2/end.png", scene, 1100, 50, false);
    auto restartButton = Object::create("Images-2/restart.png", scene, 1100, 100, false);
    auto timer = Timer::create(300.f);



    //Ÿ�̸�
    showTimer(timer);
    timer->setOnTimerCallback([&](TimerPtr)->bool {
        showMessage("FAIL");
        playButton->show();
        return true;
    });

    //������ ��ư
    endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        endGame();
        return true;
    });

    //���� ����� ��ư. �ٽ� ���´�
    restartButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        first->enter();
        playButton->show();
        return true;
    });



    //���� ��ư Ŭ��
    playButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        playButton->hide();
        endButton->show();
        restartButton->show();

        timer->set(300.f);
        timer->start();
        scene->enter();

        //������ 0~15 �� �迭 �����
        int n[16];

        for (int i = 0;i < 16;i++)
        {
            n[i] = i;
        }
        int nDust, nSour, nTemp;
        srand(int(time(NULL)));
        for (int i = 0;i < 100;i++)
        {
            nDust = rand() % 16;
            nSour = rand() % 16;

            nTemp = n[nDust];
            n[nDust] = n[nSour];
            n[nSour] = nTemp;
        }

        //�׸� ���� ��ġ
        p1->locate(scene, arr[n[0]][0], arr[n[0]][1]);
        p2->locate(scene, arr[n[1]][0], arr[n[1]][1]);
        p3->locate(scene, arr[n[2]][0], arr[n[2]][1]);
        p4->locate(scene, arr[n[3]][0], arr[n[3]][1]);

        p5->locate(scene, arr[n[4]][0], arr[n[4]][1]);
        p6->locate(scene, arr[n[5]][0], arr[n[5]][1]);
        p7->locate(scene, arr[n[6]][0], arr[n[6]][1]);
        p8->locate(scene, arr[n[7]][0], arr[n[7]][1]);

        p9->locate(scene, arr[n[8]][0], arr[n[8]][1]);
        p10->locate(scene, arr[n[9]][0], arr[n[9]][1]);
        p11->locate(scene, arr[n[10]][0], arr[n[10]][1]);
        p12->locate(scene, arr[n[11]][0], arr[n[11]][1]);

        p13->locate(scene, arr[n[12]][0], arr[n[12]][1]);
        p14->locate(scene, arr[n[13]][0], arr[n[13]][1]);
        p15->locate(scene, arr[n[14]][0], arr[n[14]][1]);
        p16->locate(scene, arr[n[15]][0], arr[n[15]][1]);

        // ������ġ��, ����ؼ� ���� ��ȭ�ϴ� ��ġ�� �迭
        int changed_arr[16][2] = { {arr[n[0]][0],arr[n[0]][1]}, {arr[n[1]][0] ,arr[n[1]][1]}, {arr[n[2]][0],arr[n[2]][1]}, {arr[n[3]][0], arr[n[3]][1]}, {arr[n[4]][0],arr[n[4]][1]}, {arr[n[5]][0],arr[n[5]][1]}, {arr[n[6]][0],arr[n[6]][1]}, {arr[n[7]][0], arr[n[7]][1]}, {arr[n[8]][0],arr[n[8]][1]}, {arr[n[9]][0], arr[n[9]][1]}, {arr[n[10]][0],arr[n[10]][1]}, {arr[n[11]][0],arr[n[11]][1]}, {arr[n[12]][0],arr[n[12]][1]}, {arr[n[13]][0],arr[n[13]][1]}, {arr[n[14]][0], arr[n[14]][1]}, {arr[n[15]][0], arr[n[15]][1]} };




        //������ ���߾����� Ȯ��. ���� ��ġ�ϸ� ���� �¸�
        bool WinGame = true;
        for (int i = 0; i < 16;++i)
        {
            for (int j = 0;j < 2;++j)
            {
                if (changed_arr[i][j] != arr[i][j])
                {
                    WinGame = false;
                    break;
                }
            }
        }
        if (WinGame)
        {
            endGame();
            return 0;
        }
        


        //�̵��ϴ� p4(���)��ư     // ���⼭���� �ణ ������ ����.
        auto moving_p4 = false;

        p4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool
        {
            if (action == MouseAction::MOUSE_DRAG_LEFT)     //p4 �������� �̵�
            {
                if (changed_arr[3][0] >= 275)     //p4�� �� ���ʿ� �ִ� ���� �ƴ϶��
                {
                    changed_arr[3][0] -= 180;
                }
           
            }
            else if (action == MouseAction::MOUSE_DRAG_RIGHT)       //p4 ���������� �̵�
            {
                if (changed_arr[3][0] < 995)     //p4�� �� �����ʿ� �ִ� ���� �ƴ϶��
                {
                    changed_arr[3][0] += 180;
                }
                
            }
            else if (action == MouseAction::MOUSE_DRAG_UP)      //p4 �������� �̵�
            {
                if (changed_arr[3][0] < 620)     //p4�� �� ���ʿ� �ִ� ���� �ƴ϶��
                {
                    changed_arr[3][0] += 180;
                }
            }
            else if (action == MouseAction::MOUSE_DRAG_DOWN)      //p4 �Ʒ��� �̵�
            {
                if (changed_arr[3][0] >= 0)     //p4�� �� �Ʒ� �ִ� ���� �ƴ϶��
                {
                    changed_arr[3][0] -= 180;
                }
            }
            p4->locate(scene, arr[n[3]][0], arr[n[3]][1]);

            return true;

        });



        return true;
    });






    //���� ����
    startGame(first);
    return 0;
}



