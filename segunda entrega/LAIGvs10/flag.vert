void main()
{
	vec4 testVec;
	testVec = vec4(-2.0, 0.0, -2.0, 0.0);
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}