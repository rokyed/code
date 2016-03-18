#version 120
  //  uniform sampler2D tex0;
struct redchan {
   float r;
}
struct matsettings
{
    redchan redchannel;
};

uniform matsettings materialsettings;

    void main(void)
    {
        gl_FragColor = vec4(1.0, 1.0, materialsettings.redchannel.r, gl_Color.w);
    }