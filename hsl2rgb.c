//in addition , two structs that i used to store values throughout the program
typedef struct{
 float r,g,b,ww,cw;
 } rgb_t;
typedef struct{
 float s,v,h;
} hsl_t;

static rgb_t hsl2rgb(hsl_t input){ 
  const float S = input.s / 100.0f;
  const float V = input.v / 100.0f;
  if(V==0){rgbcwSet(0,0,0,0,0);}
  float hue=input.h/60.0;
  float r=0;
  float g=0;
  float b=0;
  float cw = 0;
  const int x =255; //output multiply factor (output value 0-255)
  int hueI = input.h/60; 
  switch(hueI){
  case 0:r=1;g=hue;b=0; break;
  case 1:r=2-hue;g=1;b=0; break;
  case 2:b=hue-2;r=0;g=1; break;
  case 3:r=0;g=4-hue;b=1; break;
  case 4:r=hue-4;g=0;b=1; break;
  case 5:r=1;g=0;b=6-hue; break;
  }
  r=V*r;
  g=V*g;
  b=V*b;
  cw=V*(1-S)*0.5; //This calculates the white,I didn't knew what value to use, just picked one that works, you might want to change it
  //rgb_t ret={r,g,b,0.0,cw};
  rgb_t ret={r*x,g*x,b*x,0,cw*x};
  return ret;
}