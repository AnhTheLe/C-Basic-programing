#include <stdio.h>
#include <stdlib.h>

typedef struct point 
{
	double x;
	double y;
} point_t;

typedef struct circle
{
	point_t center;
	double radius;	
} circle_t;

int is_in_circle(point_t *p, circle_t *duong_tron) 
{
	double x_dist, y_dist;
	
	x_dist = p->x - duong_tron->center.x;
	y_dist = p->y - duong_tron->center.y;
	
	return (x_dist * x_dist + y_dist * y_dist <= duong_tron->radius * duong_tron->radius);
}

int main()
{
	circle_t duong_tron;
	point_t diem;
	printf("Nhap toa do tam cua duong tron: ");
	fflush(stdin);
	scanf("%lf %lf", &duong_tron.center.x, &duong_tron.center.y);
	
	printf("Nhap ban kinh duong tron: ");
	fflush(stdin);
	scanf("%lf", &duong_tron.radius);
	
	printf("Nhap toa do diem can kiem tra: ");
	fflush(stdin);
	scanf("%lf %lf", &diem.x, &diem.y);
	
	if(is_in_circle(&diem, &duong_tron))
	{
		printf("Diem do thuoc duong tron");
		return 0;
	}
	printf("Diem do khong thuoc duong tron");
	
	return 0;	
}