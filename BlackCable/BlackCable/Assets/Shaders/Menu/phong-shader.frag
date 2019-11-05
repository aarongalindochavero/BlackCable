#version 330
out vec4 colour;

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;


struct Light 
{
	vec3 myMaterialAmbient;
	vec3 myLightAmbient;
};


uniform sampler2D tex;
uniform Light light;
uniform vec3 eyePosition;

void main()
{
	const vec3 myLightPosition = vec3( 1. , 0.5, 0. );
	const vec3 myLightDiffuse = vec3( 1. , 1. , 1);
	const vec3 myLightSpecular = vec3( 1. , 1. , 1. );
	const vec3 myMaterialDiffuse = vec3( 1. , 0.5, 0. );
	const vec3 myMaterialSpecular = vec3( 0.6, 0.6, 0.6 );
	const float myMaterialShininess = 80.;
	//normal, light, view, and light reflection vectors
	vec3 norm = normalize( Normal );
	vec3 lightv = normalize( myLightPosition - eyePosition);
	vec3 viewv = normalize( vec3(0.,0.,0.) - eyePosition );
	vec3 refl = reflect( vec3(0.,0.,0.) - lightv, norm );
	//ambient light computation
	vec3 ambient = light.myMaterialAmbient*light.myLightAmbient;
	//diffuse light computation
	vec3 diffuse = max(0.0, dot(lightv, norm)) * myMaterialDiffuse
	 *myLightDiffuse;
	//specular light computation
	vec3 specular = vec3( 0.0, 0.0, 0.0 );
	if( dot(lightv, viewv) > 0.0)
	{
	 specular = pow(max(0.0, dot(viewv,refl)),
	 myMaterialShininess)*myMaterialSpecular*
	myLightSpecular;
	}
	colour =  texture(tex, TexCoord)*vec4(ambient + diffuse + specular,1.0);
}
