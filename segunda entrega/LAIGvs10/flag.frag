uniform sampler2D baseImage;

void main()
{
	gl_FragColor = vec4(1.0,1.0,1.0,0.0);
	gl_FragColor = texture2D(baseImage, gl_TexCoord[0].st);
	
}