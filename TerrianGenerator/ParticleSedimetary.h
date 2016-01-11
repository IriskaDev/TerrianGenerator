#pragma once
#include <stdlib.h>
#include <glm/glm.hpp>
#include <vector>
#include <Array2D.h>



typedef void(*rand_init_func)(unsigned);
typedef float(*rand_func)();

namespace TerrianGenerator
{
	class ParticleSedimetary
	{
	public:
		ParticleSedimetary(
			const int & width, 
			const int & length, 
			const int & height, 
			const int & searchR, 
			const float & aThreshold, 
			const float & pHeight);
		~ParticleSedimetary();
		int Walker(const int & steps);
		int InitAField();
		int DisposeAField();
		void SetStartPos(const glm::vec3 &);
		void SetRandFunc(const rand_init_func & init, const rand_func & func);
		glm::vec3 SearchAvaPosition(const glm::vec3 &);
		void RetAltitudeField();
	private:
		int width, length, height;
		// drop point search radius;
		int searchR;
		int srMul2;
		int srPow2;
		// altitude threshold
		float aThreshold;
		// particle height
		float pHeight;
		// altitude field
		typedef Utils::Array2D<float> AFieldArr;
		AFieldArr *aField;
		glm::vec3 startPos;
		glm::vec3 walkerDir8[8];
		glm::vec3 walkerDir4[4];
		rand_init_func randInit;
		rand_func randFunc;
	};
};

