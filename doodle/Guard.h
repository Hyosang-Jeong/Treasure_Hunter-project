#pragma once
#include"vec2.h"
#include"Map.h"
#include"doodle/doodle.hpp"
#include "Camera.h"
#include "Minsoo.h"
struct sight_info 
{
	math::ivec2 position;
	bool is_valid = true;  // �þ߰� ���� �����ֳ� �Ȱ����ֳ�
};

struct guard_info
{
	math::ivec2 position;
	Direction direction = Direction::UP;
	string guard_type = "guard";
	bool is_okay = true;  //�����Ծ����� �ȸԾ�����
	bool is_trace = false; //�μ��� �þ߿� ���Դ��� �ȵ��Դ���
	int trace_movement = 0;
	int movement = 0;
	sight_info sight_position[3] = { {0,true} };
	
};
class Guard :Map
{
public:
	void setup();
	void Draw_guard(Camera& camera);
	void Draw_Sight(Camera& camera,Map MAP);
	vector<guard_info> guards;
	void move(int index);
	void change_sight(Map m, int index);
	void Guard_movement_update(Map& m,int movement);
	void set_sight();
	int in_guard_sight(Minsoo minsoo); // ���� �þ߿� ������ ���° �ε��� �������� ����
	bool warning = false;
private:
	int sight_size = 3;  //�þ� ��ĭ���̴���
	int how_many_trace = 5;// ��ĭ���� ���������
	int how_many_craze = 3;//�󸶵��� �����԰� �����ִ���
	doodle::Image GuardUP_image{ "assets/GuardUp.png" };
	doodle::Image GuardDown_image{ "assets/GuardDown.png" };
	doodle::Image GuardRight_image{ "assets/GuardRight.png" };
	doodle::Image GuardLeft_image{ "assets/GuardLeft.png" };
	doodle::Image Guard_CHEW_image{ "assets/chew_dog.png" }; //���Դ°�
	doodle::Image Guard_tracing_image{ "assets/tracing_dog.png" };
	doodle::Image Ruby_image{ "assets/Ruby.png" };

	doodle::Image Sight1_up_image{ "assets/sight1_up.png" };
	doodle::Image Sight2_up_image{ "assets/sight2_up.png" };
	doodle::Image Sight3_up_image{ "assets/sight3_up.png" };

	doodle::Image Sight1_down_image{ "assets/sight1_down.png" };
	doodle::Image Sight2_down_image{ "assets/sight2_down.png" };
	doodle::Image Sight3_down_image{ "assets/sight3_down.png" };

	doodle::Image Sight1_right_image{ "assets/sight1_right.png" };
	doodle::Image Sight2_right_image{ "assets/sight2_right.png" };
	doodle::Image Sight3_right_image{ "assets/sight3_right.png" };

	doodle::Image Sight1_left_image{ "assets/sight1_left.png" };
	doodle::Image Sight2_left_image{ "assets/sight2_left.png" };
	doodle::Image Sight3_left_image{ "assets/sight3_left.png" };
};