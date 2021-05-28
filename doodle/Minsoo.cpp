#include"Minsoo.h"

void Minsoo::Draw_minsu(Camera camera,[[maybe_unused]]bool camera_move)
{
	doodle::set_fill_color(255, 255, 0);
	switch (direction)
	{
	case Direction::DOWN:
		doodle::draw_image(Minsoo_Down, (position.x + camera.Get_position().x) * block_size, (position.y + camera.Get_position().y) * block_size, block_size, block_size);
		break;
	case Direction::UP:
		doodle::draw_image(Minsoo_Up, (position.x + camera.Get_position().x) * block_size, (position.y + camera.Get_position().y) * block_size, block_size, block_size);
		break;
	case Direction::RIGHT:
		doodle::draw_image(Minsoo_right, (position.x + camera.Get_position().x) * block_size, (position.y + camera.Get_position().y) * block_size, block_size, block_size);
		break;
	case Direction::LEFT:
		doodle::draw_image(Minsoo_left, (position.x + camera.Get_position().x) * block_size, (position.y + camera.Get_position().y) * block_size, block_size, block_size);
		break;
	}


#ifdef _DEBUG

#else
	/*if (camera_move == false)
	{
		doodle::push_settings();
		for (int i{ 0 }; i < 200; i++)
		{
			doodle::no_fill();
			doodle::set_outline_width(100);
			doodle::set_outline_color(0);
			doodle::draw_ellipse((position.x + 0.5 + camera.Get_position().x) * block_size, (position.y + 0.5 + camera.Get_position().y) * block_size, 350 + i * 10.0);
		}
		doodle::pop_settings();
	}*/
#endif
	doodle::draw_text(to_string(movement),0,80);
}
void Minsoo::Set_up()
{
	position = math::ivec2{ 2,2 };
	movement = 0;
	chew_item = 3;
	bomb_item = 1;
	explode_count = -1;
	target_pos = position;
}

void Minsoo::Set_position(doodle::KeyboardButtons button)
{
	target_pos = Get_position();  //fist set curr pos

	switch (button)
	{
	case doodle::KeyboardButtons::S:
	{
		target_pos.y += 1;
		direction = Direction::DOWN;
	}
		break;
	case doodle::KeyboardButtons::A:
		{
		target_pos.x -= 1;
		direction = Direction::LEFT;

		}
		break;
	case doodle::KeyboardButtons::D:
		{
		target_pos.x += 1;			
		direction = Direction::RIGHT;
		}
		break;
	case doodle::KeyboardButtons::W:
		{
		target_pos.y -= 1;
		direction = Direction::UP;
		}
		break;
	}


}

void Minsoo::Update_position(bool& is_move)
{
	if (is_move == true)
	{
		if (position.x > target_pos.x)
		{
			position.x -= doodle::DeltaTime * 2;
			if (position.x <= target_pos.x)
			{
				position.x = target_pos.x;
				is_move = false;
				movement++;
			}
		}
		else if (position.x < target_pos.x)
		{
			position.x += doodle::DeltaTime * 2;
			if (position.x >= target_pos.x)
			{
				position.x = target_pos.x;
				is_move = false;
				movement++;
			}
		}

		else if (position.y > target_pos.y)
		{
			position.y -= doodle::DeltaTime * 2;
			if (position.y <= target_pos.y)
			{
				position.y = target_pos.y;
				is_move = false;
				movement++;
			}
		}
		else if (position.y < target_pos.y)
		{
			position.y += doodle::DeltaTime * 2;
			if (position.y >= target_pos.y)
			{
				position.y = target_pos.y;
				is_move = false;
				movement++;
			}
		}
	}
}

math::vec2 Minsoo::Get_position()
{
	return position;
}

