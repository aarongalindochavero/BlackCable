#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 colour;

const int MAX_POINT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];

uniform sampler2D theTexture;
uniform sampler2D normalMap;  
uniform Material material;

uniform vec3 eyePosition;

vec4 CalcLightByDirection(Light light, vec3 direction)
{
	vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
	
	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour * light.diffuseIntensity * diffuseFactor, 1.0f);
	
	vec4 specularColour = vec4(0, 0, 0, 0);
	
	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);
		vec3 reflectedVertex = normalize(reflect(direction, normalize(Normal)));
		
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}

	return (ambientColour + diffuseColour + specularColour);
}

vec4 CalcDirectionalLight()
{
	return CalcLightByDirection(directionalLight.base, directionalLight.direction);
}

vec4 CalcPointLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < pointLightCount; i++)
	{
		vec3 direction = FragPos - pointLights[i].position;
		float distance = length(direction);
		direction = normalize(direction);
		
		vec4 colour = CalcLightByDirection(pointLights[i].base, direction);
		float attenuation = pointLights[i].exponent * distance * distance +
							pointLights[i].linear * distance +
							pointLights[i].constant;
		
		totalColour += (colour / attenuation);
	}
	
	return totalColour;
}

void main()
{
	//Normal = texture(normalMap, fs_in.TexCoords).rgb;
//    // transform normal vector to range [-1,1]
//    Normal = normalize(Normal * 2.0 - 1.0);   
	vec4 finalColour = CalcDirectionalLight();
	finalColour += CalcPointLights();
	
	colour = texture(normalMap, TexCoord) * finalColour;
}

//#version 330
//out vec4 colour;
//
//in vec4 vCol;
//in vec2 TexCoord;
//in vec3 Normal;
//in vec3 FragPos;
//
//struct Light 
//{
//	vec3 myMaterialAmbient;
//	vec3 myLightAmbient;
//};
//
//
//uniform sampler2D tex;
//uniform Light light;
//uniform vec3 eyePosition;
//
//void main()
//{
//	const vec3 myLightPosition = vec3( 1. , 0.5, 0. );
//	const vec3 myLightDiffuse = vec3( 1. , 1. , 1);
//	const vec3 myLightSpecular = vec3( 1. , 1. , 1. );
//	const vec3 myMaterialDiffuse = vec3( 1. , 0.5, 0. );
//	const vec3 myMaterialSpecular = vec3( 0.6, 0.6, 0.6 );
//	const float myMaterialShininess = 80.;
//	//normal, light, view, and light reflection vectors
//	vec3 norm = normalize( Normal );
//	vec3 lightv = normalize( myLightPosition - eyePosition);
//	vec3 viewv = normalize( vec3(0.,0.,0.) - eyePosition );
//	vec3 refl = reflect( vec3(0.,0.,0.) - lightv, norm );
//	//ambient light computation
//	vec3 ambient = light.myMaterialAmbient*light.myLightAmbient;
//	//diffuse light computation
//	vec3 diffuse = max(0.0, dot(lightv, norm)) * myMaterialDiffuse
//	 *myLightDiffuse;
//	//specular light computation
//	vec3 specular = vec3( 0.0, 0.0, 0.0 );
//	if( dot(lightv, viewv) > 0.0)
//	{
//	 specular = pow(max(0.0, dot(viewv,refl)),
//	 myMaterialShininess)*myMaterialSpecular*
//	myLightSpecular;
//	}
//	colour =  texture(tex, TexCoord)*vec4(ambient + diffuse + specular,1.0);
//}
//