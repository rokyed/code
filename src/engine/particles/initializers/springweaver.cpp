#include "cube.h"
#include "engine/particles/particles.h"

/**
 * Spring weaver:
 * 1. Raster with distances: size_x, size_y, size_z
 * 2.
 */
struct spring_weaver : public particle_initializer_implementation
{

public:

	static spring_weaver& instance()
	{
		static spring_weaver _instance;
		return _instance;
	}
	virtual ~spring_weaver() { }

	inline void init(particle_initializer_instance *pi_inst, std::list<particle_instance *> particles, int elapsedtime) {

		spring_constant = pi_inst->attributes["spring_constant"];
		spring_friction = pi_inst->attributes["spring_friction"];
		spring_length_x = pi_inst->attributes["spring_length_x"];
		spring_length_y = pi_inst->attributes["spring_length_y"];
		spring_length_z = pi_inst->attributes["spring_length_z"];
		size_x = (int) pi_inst->attributes["size_x"];
		size_y = (int) pi_inst->attributes["size_y"];
		size_z = (int) pi_inst->attributes["size_z"];

		// init matrix [size_x, size_y, size_z]
		std::vector<std::vector<std::vector<particle_instance *> > > matrix(size_x);
		for (x = 0; x < size_x; x++)
		{
			matrix[x].resize(size_y);
			for (y = 0; y < size_y; y++) matrix[x][y].resize(size_z);
		}

		// transform 1D list of particles into a 3D matrix
		int p = 0;
		for(std::list<particle_instance*>::iterator p_it = particles.begin(); p_it != particles.end(); ++p_it)
		{
			// 2D
			// matrix[p / size_x][p % size_x] = (*p_it);
			// p++;
			// 3D
			z = p / (size_x * size_y);
			y = (p % (size_x * size_y)) / size_x;
			x = p - y * size_x - z * size_x * size_y;
			matrix[x][y][z] = (*p_it);
			p++;
		}

		// connect particles in the matrix by construction rules
		std::vector<std::string> *rules = static_cast<std::vector<std::string>*>(pi_inst->pointers["rules"]);
		// conoutf("%d spring construction rules", (int) rules->size());
		for (x = 0; x < size_x; x++)
		{
			for (y = 0; y < size_y; y++)
			{
				for (z = 0; z < size_z; z++)
				{
					for (std::vector<std::string>::iterator it = rules->begin() ; it != rules->end(); ++it)
					{
						ivec spring_construction_rule = ps.spring_construction_rules[(*it)];
						ivec t = ivec(x, y, z).add(spring_construction_rule);
						if (t.x >= 0 && t.x < size_x && t.y >= 0 && t.y < size_y && t.z >= 0 && t.z < size_z)
						{
							slx = spring_length_x * (float) spring_construction_rule.x;
							sly = spring_length_y * (float) spring_construction_rule.y;
							slz = spring_length_z * (float) spring_construction_rule.z;
							spring_length = sqrt((slx * slx) + (sly * sly) + (slz * slz));
							create_spring(matrix[x][y][z], matrix[t.x][t.y][t.z], spring_constant, spring_friction, spring_length);
						}
					}
				}
			}
		}
	}

	void create_spring(particle_instance *p1, particle_instance *p2, float spring_constant, float spring_friction, float spring_length)
	{
		// conoutf("p1:%d", p1->remaining);
		// conoutf("p2:%d", p2->remaining);
		spring_instance *spring_inst = new spring_instance;
		spring_inst->p_inst_1 = p1;
		spring_inst->p_inst_2 = p2;
		spring_inst->spring_constant = spring_constant;
		spring_inst->spring_friction = spring_friction;
		spring_inst->spring_length = spring_length;
		spring_inst->alive = true;
		ps.add_spring(spring_inst);
	}

	void render_edit_overlay(particle_initializer_instance *entity_instance) { }

private:

	float time_factor;
	float spring_constant;
	float spring_friction;
	float spring_length;
	int size_x;
	int size_y;
	int size_z;
	int spring_length_x;
	int spring_length_y;
	int spring_length_z;

	float slx;
	float sly;
	float slz;
	int x;
	int y;
	int z;

	spring_weaver() : particle_initializer_implementation("spring_weaver") {
		ps.add_initializer_implementation(this);
		time_factor = 0.0f;
		spring_constant = 0.1f;
		spring_friction = 0.95f;
		spring_length = 10.0f;
		size_x = 0;
		size_y = 0;
		size_z = 0;
		spring_length_x = 0.0f;
		spring_length_y = 0.0f;
		spring_length_z = 0.0f;
		slx = 0.0f;
		sly = 0.0f;
		slz = 0.0f;
		x = 0;
		y = 0;
		z = 0;
	}
	spring_weaver( const spring_weaver& );
	spring_weaver & operator = (const spring_weaver &);

};

spring_weaver& ps_initializer_spring_weaver = spring_weaver::instance();