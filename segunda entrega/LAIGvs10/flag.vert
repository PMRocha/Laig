void main()
{
	vec4 testVec;
	vec4 wave;
	testVec = vec4(0.1, 0.0, 0.1, 0.0);
	wave = vec4(0.0, 0.2 * sin(50 * gl_Vertex.x), 0.0, 0.0);
	gl_Position = gl_ModelViewProjectionMatrix * (gl_Vertex + testVec + wave);
}