#include<GLUT/GLUT.h>

void draw_dotted_line_pixel(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void draw_dotted_line(int x1,int x2,int y1,int y2)
{
    int dx,dy,p,i,xinc=1,yinc=1,inc1,inc2,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(dx<0)
        dx=-dx;
    if(dy<0)
        dy=-dy;
    if(x2<x1)
        xinc=-1;
    if(y2<y1)
        yinc=-1;
    x=x1;
    y=y1;

    if(dx>dy)
    {
        draw_dotted_line_pixel(x,y);
        p=2*dy-dx;
        inc1=2*(dy-dx);
        inc2=2*dy;
        int flag=5;
        for(i=0;i<dx;i++)
        {
            if(p>=0)
            {
                y+=yinc;
                p+=inc1;
            }
            else
                p+=inc2;
            x+=xinc;
            if(flag<0)
            {
            draw_dotted_line_pixel(x,y);
            flag=5;
            }
            else
                flag--;

        }
    }
    else
    {
        draw_dotted_line_pixel(x,y);
        p=2*dx-dy;
        inc1=2*(dx-dy);
        inc2=2*dx;
        int flag=5;
        for(i=0;i<dy;i++)
        {
            if(p>=0)
            {
                x+=xinc;
                p+=inc1;
            }
            else
                p+=inc2;
            y+=yinc;
            if(flag<0)
            {
                draw_dotted_line_pixel(x,y);
                flag=5;
            }
            else
                flag--;
        }
    }
}