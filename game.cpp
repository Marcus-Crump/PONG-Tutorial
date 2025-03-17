#define isDown(b) input->buttons[b].isDown
#define isPressed(b) (input->buttons[b].isDown && input->buttons[b].changed)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].changed)

float p1pos, p2pos, p1vel, p2vel = 0.f;
float arenaHSx = 85, arenaHSy = 45; 
float pHSx = 2.5, pHSy = 12;
float ballx, bally, ballxVel = 100, ballyVel, ballHS= 1;

internal void
simulateGame(Input* input, float dt) {
    float p1accel, p2accel = 0.f;
    clearScreen(0xff5500);
    drawRect(0,0,arenaHSx,arenaHSy,0xffaa33);
    

    if (isDown(BUTTON_W)) {p1accel+=2000;}
    if(isDown(BUTTON_S)) {p1accel-=2000;}

    p1accel -= p1vel * 10.f;
    p1pos += p1vel * dt + p1accel *dt *dt * .5f;
    p1vel += p1accel*dt;

    if(p1pos + pHSy > arenaHSy) {
        p1pos = arenaHSy - pHSy;
        p1vel *= 0;
    }
    else if(p1pos - pHSy < -arenaHSy) {
        p1pos = -arenaHSy + pHSy;
        p1vel *= 0;
    }


    if (isDown(BUTTON_UP)) {p2accel+=2000;}
    if(isDown(BUTTON_DOWN)) {p2accel-=2000;}

    p2accel -= p2vel * 10.f;
    p2pos += p2vel * dt + p1accel *dt *dt * .5f;
    p2vel += p2accel*dt;

    if(p2pos + pHSy > arenaHSy) {
        p2pos = arenaHSy - pHSy;
        p2vel *= 0;
    }
    else if(p2pos - pHSy < -arenaHSy) {
        p2pos = -arenaHSy + pHSy;
        p2vel *= 0;
    }
    
    
    
    if(ballx + ballHS > 80 - pHSx &&
    ballx - ballHS < 80 + pHSx &&
    bally + ballHS > p2pos - pHSy &&
    bally - ballHS < p2pos + pHSy) {
        ballx = 80 - pHSx - ballHS;
        ballxVel*=-1;
        ballyVel = p2vel;
    }else if(ballx - ballHS < -80 - pHSx &&
    ballx + ballHS > -80 - pHSx &&
    bally - ballHS < p1pos + pHSy &&
    bally + ballHS > p1pos - pHSy) {
        ballx = -80 + pHSx + ballHS;
        ballxVel*=-1;
        ballyVel= p1vel;
    }
    if(bally + ballHS > arenaHSy - ballHS) {
        ballyVel*=-1;
    }else if(bally - ballHS < -arenaHSy + ballHS) {
        ballyVel *=-1;
    }
    if(ballx >= arenaHSx) {
        ballx = 0;
        bally = 0;
        ballxVel = -100;
        ballyVel = 0;
    }else if(ballx <= -arenaHSx) {
        ballx = 0;
        bally = 0;
        ballxVel = 100;
        ballyVel = 0;
    }

    ballx += ballxVel *dt;
    bally += ballyVel *dt;

    drawRect(ballx, bally, ballHS, ballHS, 0xffffff);
    drawRect(-80, p1pos, pHSx, pHSy, 0xffffff);
    drawRect(80, p2pos, pHSx, pHSy, 0xffffff);
    
    
        
}