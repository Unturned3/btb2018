#include <stdio.h>
#include <botball.h>
#include <wallaby.h>

int main()
{
	camera_open_black();	// open cam
	int r = camera_load_config("red");
	printf("config load state: %d\n", r);

	while(getchar() != 'p')
	{
		camera_update();	// get a new image
		int c = get_object_count(0);	// channel 0 in green.conf
		int a = get_object_area(0, 0);
		printf("obj area: %d\n", a);
		if(c == 0)
			printf("no objects detected on channel 0\n");
		else
			if(get_object_center_x(0, 0) > 60 && get_object_center_x(0, 0) < 100) 
				printf("object centered\n");
			else if(get_object_center_x(0, 0) >= 100)
				printf("object on the right\n");
			else
				printf("object on the left\n");
	}

	camera_close();	// close connection
	return 0;
}
