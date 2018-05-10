#include "genesis.h"

struct hashChar
{
    int x;
    int y;
};

char* sn = ".";

void move(struct hashChar* h)
{
    h->x++;
    h->y++;
    h->y++;
    if(h->x>38)
    {
        h->x = 0;
    }
    if(h->y>28)
    {
        h->y = 0;
    }
}

void draw(struct hashChar* h)
{
    VDP_drawText(sn, h->x, h->y);
}

void update(struct hashChar* h)
{
    move(h);
    draw(h);
}

u16 randomNumberGenerator(u16 startInt, u16 finishInt) 
{
    if (finishInt != 0)
    {
        u16 x = ( random() % (finishInt - startInt) ) + startInt;
        return x;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct hashChar hashes[10];
    char* sn = ".";

    for (u16 i=0;i<10;i++)
    {
        hashes[i].x = randomNumberGenerator(0,38);
        hashes[i].y = randomNumberGenerator(0,28);
    }
    
    while(1)
    {
        for(u16 i=0;i<10;i++)
        {
            update(&hashes[i]);
        }
        
        VDP_waitVSync(); 
        VDP_init(); 
    }
	return (0);
}

