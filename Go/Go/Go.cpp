// Go.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <stdio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_windows.h>

//global variables
const int width = 800;
const int height = 800;
const char FONT_NAME[] = "ARIALI.TTF";
const char IMAGE_DROGON[] = "dragon_background.jpg";
const char musName[30] = "file_(donkool.com)-10-10.ogg";
const char pass[] = "Pass";

//initialize display ================================================================================================
int init_display() {
	if (!al_init()) {
		al_show_native_message_box(al_get_current_display(),
			"Error",
			"Could not init",
			"Failed to initialize allegro!\n",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	al_set_window_position(display, 500, 100);
	al_set_window_title(display, "GO");
	al_clear_to_color(al_map_rgb(226, 173, 50));
	al_flip_display();
	return 0;
}

//print text ========================================================================================================
void print_text(const char text[], int x, int y, int R = 255, int G = 255, int B = 255, const char
	font_name[] = FONT_NAME) {
	ALLEGRO_FONT *font = al_load_ttf_font("ARIALI.TTF", 25, 5);
	al_draw_text(font, al_map_rgb(R, G, B), x, y, 0, text);
	al_flip_display();
}


//show massages ==========================================
int message_box(const char* message,
	const char* content_title,
	const char* title)
{
	switch (al_show_native_message_box(
		al_get_current_display(),
		title,
		content_title,
		message, NULL,
		ALLEGRO_MESSAGEBOX_WARN)
		)
	{
	case 0: return 0;                       // User pressed the Cancel button
	case 1: return 1;                       // User pressed the OK button
	}
}


//bitmap for background =============================================================================================
void create_bitmap_dragon(const char image_name[], float x, float y, int width, int height) {
	ALLEGRO_BITMAP *image = NULL;
	image = al_load_bitmap("dragon_background.jpg");
	al_draw_scaled_bitmap(image,
		0, 0,                             // source origin
		al_get_bitmap_width(image),       // source width
		al_get_bitmap_height(image),      // source height
		x, y,                             // target origin
		width, height,                    // target dimensions
		0                                 // flags
	);
	al_flip_display();
}


//bitmap for white stone ============================================================================================
void create_bitmap_white_stone(const char image_name[], float x, float y, int width, int height) {
	ALLEGRO_BITMAP *image = NULL;
	image = al_load_bitmap("white_stone.png");
	al_draw_scaled_bitmap(image,
		0, 0,                             // source origin
		al_get_bitmap_width(image),       // source width
		al_get_bitmap_height(image),      // source height
		x, y,                             // target origin
		width, height,                    // target dimensions
		0                                 // flags
	);
	al_flip_display();
}

//bitmap for black stone ============================================================================================
void create_bitmap_black_stone(const char image_name[], float x, float y, int width, int height) {
	ALLEGRO_BITMAP *image = NULL;
	image = al_load_bitmap("black.png");
	al_draw_scaled_bitmap(image,
		0, 0,                             // source origin
		al_get_bitmap_width(image),       // source width
		al_get_bitmap_height(image),      // source height
		x, y,                             // target origin
		width, height,                    // target dimensions
		0                                 // flags
	);
	al_flip_display();
}

//drawing pass bottom ==============================
void draw_pass_bottom()
{
	al_draw_filled_rectangle(700, 740, 790, 790, al_map_rgb(226, 173, 50));
	print_text(pass, 720, 750, 0, 0, 0, "ARIALI.TTF");
	al_flip_display();
}
void draw_pass_bottom_click()
{
	al_draw_filled_rectangle(700, 740, 790, 790, al_map_rgb(181, 133, 26));
	print_text(pass, 720, 750, 0, 0, 0, "ARIALI.TTF");
	al_flip_display();
}


//drawing display
void draw_display()
{
	//background
	create_bitmap_dragon("dragon_background.jpg", 0, 0, 800, 800);

	// draw chart ================================================================================
	for (int i = 0; i < 9; i++)
	{
		al_draw_line(125 + (i * 70), 125, 125 + (i * 70), 685, al_map_rgb(0, 0, 0), 3);
		al_draw_line(125, 125 + (i * 70), 685, 125 + (i * 70), al_map_rgb(0, 0, 0), 3);
		al_flip_display();
	}
	// drawing circles ===========================================================================
	al_draw_filled_circle(265, 265, 7, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(265, 545, 7, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(405, 405, 7, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(545, 265, 7, al_map_rgb(0, 0, 0));
	al_draw_filled_circle(545, 545, 7, al_map_rgb(0, 0, 0));

	// drawing borders ============================================================================
	al_draw_rectangle(125, 125, 685, 685, al_map_rgb(0, 0, 0), 6);
	al_flip_display();

	//printing letters ============================================================================
	int aski = 64;
	for (int i = 0; i < 9; i++) {
		aski++;
		char temp = (char)aski;
		char javab[] = { temp,'\0' };
		print_text(javab, 115 + 70 * i, 50, 0, 0, 0, "ARIALI.TTF");
		print_text(javab, 115 + 70 * i, 735, 0, 0, 0, "ARIALI.TTF");
	}
	//printing numbers =============================================================================
	int num = 48;
	for (int i = 0; i < 9; i++)
	{
		num++;
		char NUM = (char)num;
		char javab1[] = { NUM ,'\0' };
		print_text(javab1, 50, 110 + 70 * i, 0, 0, 0, "SHOWG.TTF");
		print_text(javab1, 735, 110 + 70 * i, 0, 0, 0, "SHOWG.TTF");
	}
	al_flip_display();

	//pass bottom
	draw_pass_bottom();
}


//function of pass
void function_pass(bool &pass_Pl_1, bool &pass_Pl_2, int &turn)
{
	draw_pass_bottom_click();
	if (turn == 1)
	{
		pass_Pl_1 = true;
		turn *= (-1);
	}
	else if (turn == -1)
	{
		pass_Pl_2 = true;
		turn *= (-1);
	}
}


//rulls of game (capturing)
void capture(int i, int j, int stone_array[9][9])
{
	int lowest_col = j;
	int lowest_row = i;
	int highest_col = j;
	int highest_row = i;
	if (stone_array[i][j] == 1)
	{
		if (stone_array[i + 1][j] == 1)
		{
			highest_row = i + 1;
			capture(i + 1, j, stone_array);
		}
		if (stone_array[i - 1][j] == 1)
		{
			lowest_row = i - 1;
			capture(i - 1, j, stone_array);
		}
		if (stone_array[i][j + 1] == 1)
		{
			highest_col = j + 1;
			capture(i, j + 1, stone_array);
		}
		if (stone_array[i][j - 1] == 1)
		{
			lowest_col = j - 1;
			capture(i, j - 1, stone_array);
		}
		if (stone_array[i + 1][j + 1] == 1)
		{
			highest_row = i + 1;
			highest_col = j + 1;
			capture(i + 1, j + 1, stone_array);
		}
		if (stone_array[i + 1][j - 1] == 1)
		{
			highest_row = i + 1;
			lowest_col = j - 1;
			capture(i + 1, j - 1, stone_array);
		}
		if (stone_array[i - 1][j + 1] == 1)
		{
			lowest_row = i - 1;
			highest_col = j + 1;
			capture(i - 1, j + 1, stone_array);
		}
		if (stone_array[i - 1][j - 1] == 1)
		{
			lowest_row = i - 1;
			lowest_col = j - 1;
			capture(i - 1, j - 1, stone_array);
		}
		for (int r = lowest_row; r < highest_row; r++)
		{
			for (int c = lowest_col; c < highest_col && stone_array[r][j] == 2; c++)
			{
				stone_array[r][c] = 0;
			}
		}

	}
	else if (stone_array[i][j] == 2)
	{
		if (stone_array[i + 1][j] == 2)
		{
			highest_row = i + 1;
			capture(i + 1, j, stone_array);
		}
		if (stone_array[i - 1][j] == 2)
		{
			lowest_row = i - 1;
			capture(i - 1, j, stone_array);
		}
		if (stone_array[i][j + 1] == 2)
		{
			highest_col = j + 1;
			capture(i, j + 1, stone_array);
		}
		if (stone_array[i][j - 1] == 2)
		{
			lowest_col = j - 1;
			capture(i, j - 1, stone_array);
		}
		if (stone_array[i + 1][j + 1] == 2)
		{
			highest_row = i + 1;
			highest_col = j + 1;
			capture(i + 1, j + 1, stone_array);
		}
		if (stone_array[i + 1][j - 1] == 2)
		{
			highest_row = i + 1;
			lowest_col = j - 1;
			capture(i + 1, j - 1, stone_array);
		}
		if (stone_array[i - 1][j + 1] == 2)
		{
			lowest_row = i - 1;
			highest_col = j + 1;
			capture(i - 1, j + 1, stone_array);
		}
		if (stone_array[i - 1][j - 1] == 2)
		{
			lowest_row = i - 1;
			lowest_col = j - 1;
			capture(i - 1, j - 1, stone_array);
		}
		for (int r = lowest_row; r < highest_row; r++)
		{
			for (int c = lowest_col; c < highest_col && stone_array[r][j] == 1; c++)
			{
				stone_array[r][c] = 0;
			}
		}
	}
}


//finding the positon of mouse ======================================================================================
void mouse_position(float cursor_x, float cursor_y, bool pass_Pl_1, bool pass_Pl_2, int &turn, int stone_array[9][9])
{
	if (cursor_x >= 700 && cursor_x <= 790 && cursor_y >= 740 && cursor_y <= 790)
	{
		function_pass(pass_Pl_1, pass_Pl_2, turn);
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			int first_range_x = 90;
			int end_range_x = 160;
			first_range_x += i * 70;
			end_range_x += i * 70;

			if (cursor_x > first_range_x && cursor_x < end_range_x)
			{
				for (int j = 0; j < 9; j++)
				{
					int first_range_y = 90;
					int end_range_y = 160;
					first_range_y += j * 70;
					end_range_y += j * 70;
					if (cursor_y > first_range_y && cursor_y < end_range_y && stone_array[i][j] == 0)
					{
						if (turn == -1)
						{
							create_bitmap_black_stone("black.png", end_range_x - 60, end_range_y - 60, 50, 50);
							stone_array[i][j] = 2;
							turn *= (-1);
						}
						else if (turn == 1)
						{
							create_bitmap_white_stone("white_stone.png", end_range_x - 60, end_range_y - 60, 50, 50);
							stone_array[i][j] = 1;
							turn *= (-1);
						}
						al_flip_display();
					}
				}
			}
		}
	}
}


//putting stones by enter
void key_enter(int pos_x, int pos_y, bool pass_PL_1, bool pass_PL_2, int &turn, int stone_array[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (pos_x == 125 + i * 70 && pos_y == 125 + j * 70 && stone_array[i][j] == 0)
			{
				if (turn == -1)
				{
					create_bitmap_black_stone("black.png", pos_x - 25, pos_y - 25, 50, 50);
					stone_array[i][j] = 2;
					turn *= -1;
				}
				else if (turn == 1)
				{
					create_bitmap_white_stone("white_stone.png", pos_x - 25, pos_y - 25, 50, 50);
					stone_array[i][j] = 1;
					turn *= -1;
				}
			}
		}
	}

}



int main()
{
	//boolian variable ==================
	bool done = false;
	bool redraw = true;
	bool pass_Pl_1 = false;
	bool pass_Pl_2 = false;

	//variable ==========================
	int pos_x = 125;
	int pos_y = 125;
	int turn = 1;
	int stone_array[9][9] = { 0 };
	float cursor_x = 0;
	float cursor_y = 0;

	//init ==============================
	init_display();
	al_init_primitives_addon();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_image_addon();
	al_init_native_dialog_addon();
	al_init_ttf_addon();
	//install ===========================
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();

	al_reserve_samples(1);
	// allegro variable =========================================================
	ALLEGRO_SAMPLE *sample = al_load_sample(musName);
	ALLEGRO_SAMPLE_INSTANCE *sampleInstance = al_create_sample_instance(sample);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	al_set_sample_instance_playmode(sampleInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());
	al_play_sample_instance(sampleInstance);

	//al_register ================================================================================
	al_register_event_source(event_queue, al_get_display_event_source(al_get_current_display()));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	// playing audio =============================================================================
	al_play_sample(sample, 10, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
	
	//show display
	draw_display();

	// events =======================================================================================
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//keyboard events ===============================================================
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				pos_y -= 70;
				break;
			case ALLEGRO_KEY_DOWN:
				pos_y += 70;
				break;
			case ALLEGRO_KEY_RIGHT:
				pos_x += 70;
				break;
			case ALLEGRO_KEY_LEFT:
				pos_x -= 70;
				break;
			case ALLEGRO_KEY_ENTER:
				key_enter(pos_x, pos_y, pass_Pl_1, pass_Pl_2, turn, stone_array);
				break;
			}
			if (pos_x >= 125 && pos_x <= 685 && pos_y >= 125 && pos_y <= 685)
			{
				al_draw_filled_circle(pos_x, pos_y, 20, al_map_rgb(196, 196, 196));
				al_flip_display();
			}
			else if (pos_x < 125 || pos_x > 685 || pos_y < 125 || pos_y > 685)
			{
				pos_x = 125;
				pos_y = 125;
				al_draw_filled_circle(pos_x, pos_y, 20, al_map_rgb(196, 196, 196));
				al_flip_display();
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			cursor_x = ev.mouse.x;
			cursor_y = ev.mouse.y;

			//putting stones ===========================================================
			mouse_position(cursor_x, cursor_y, pass_Pl_1, pass_Pl_2, turn, stone_array);
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (cursor_x >= 700 && cursor_x <= 790 && cursor_y >= 740 && cursor_y <= 790)
				draw_pass_bottom();
			/*if (pass_Pl_1)
				message_box("Player1 passed", "warning", "warning");
			else if (pass_Pl_2)
				message_box("Player2 passed", "warning", "warning");*/
			pass_Pl_1 = false;
			pass_Pl_2 = false;
		}
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
		}
		al_flip_display();
	}

	//destroy objects ===================
	al_destroy_sample(sample);
	al_destroy_sample_instance(sampleInstance);
	al_destroy_event_queue(event_queue);
}



