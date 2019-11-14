#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent; 



out vec4 vCol;
out vec2 TexCoord;
out vec3 FragPos;
out mat3 TBN;
out vec3 Normal;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{


	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	
	TexCoord = tex;
	
	
	vec3 T = normalize(vec3(model * vec4(tangent,   0.0)));
	vec3 B = normalize(vec3(model * vec4(bitangent, 0.0)));
	vec3 N = normalize(vec3(model * vec4(norm,    0.0)));
	Normal = N;
	TBN = mat3(T, B, N);
	FragPos = (model * vec4(pos, 1.0)).xyz; 
}

//#version 330
//
//layout (location = 0) in vec3 pos;
//layout (location = 1) in vec2 tex;
//layout (location = 2) in vec3 norm;
//
//out vec2 TexCoord;
//out vec3 Normal;
//out vec3 FragPos;
//
//uniform mat4 model;
//uniform mat4 projection;
//uniform mat4 view;
//
//
//void main( )
//{
//	gl_Position = projection * view * model * vec4(pos, 1.0);
//	TexCoord = tex;
//
//	Normal = (model * vec4(norm, 1.0)).xyz; 
//	
//	FragPos = (model * vec4(pos, 1.0)).xyz; 
//}
//