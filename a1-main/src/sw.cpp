#include "sw.hpp"

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./util/util.hpp"
 
namespace COL781 {
	namespace Software {

		// Forward declarations

		template <> float Attribs::get(int index) const;
		template <> glm::vec2 Attribs::get(int index) const;
		template <> glm::vec3 Attribs::get(int index) const;
		template <> glm::vec4 Attribs::get(int index) const;

		template <> void Attribs::set(int index, float value);
		template <> void Attribs::set(int index, glm::vec2 value);
		template <> void Attribs::set(int index, glm::vec3 value);
		template <> void Attribs::set(int index, glm::vec4 value);

		// Built-in shaders

		VertexShader Rasterizer::vsIdentity() {
			return [](const Uniforms &uniforms, const Attribs &in, Attribs &out) {
				glm::vec4 vertex = in.get<glm::vec4>(0);
				return vertex;
			};
		}

		VertexShader Rasterizer::vsTransform() {
			return [](const Uniforms &uniforms, const Attribs &in, Attribs &out) {
				glm::vec4 vertex = in.get<glm::vec4>(0);
				glm::mat4 transform = uniforms.get<glm::mat4>("transform");
				return transform * vertex;
			};
		}

		VertexShader Rasterizer::vsColor() {
			return [](const Uniforms &uniforms, const Attribs &in, Attribs &out) {
				glm::vec4 vertex = in.get<glm::vec4>(0);
				glm::vec4 color = in.get<glm::vec4>(1);
				out.set<glm::vec4>(0, color);
				return vertex;
			};
		}


		FragmentShader Rasterizer::fsConstant() {
			return [](const Uniforms &uniforms, const Attribs &in) {
				glm::vec4 color = uniforms.get<glm::vec4>("color");
				return color;
			};
		}

		FragmentShader Rasterizer::fsIdentity() {
			return [](const Uniforms &uniforms, const Attribs &in) {
				glm::vec4 color = in.get<glm::vec4>(0);
				return color;
			};
		}

		// Implementation of Attribs and Uniforms classes

		void checkDimension(int index, int actual, int requested) {
			if (actual != requested) {
				std::cout << "Warning: attribute " << index << " has dimension " << actual << " but accessed as dimension " << requested << std::endl;
			}
		}

		template <> float Attribs::get(int index) const {
			checkDimension(index, dims[index], 1);
			return values[index].x;
		}

		template <> glm::vec2 Attribs::get(int index) const {
			checkDimension(index, dims[index], 2);
			return glm::vec2(values[index].x, values[index].y);
		}

		template <> glm::vec3 Attribs::get(int index) const {
			checkDimension(index, dims[index], 3);
			return glm::vec3(values[index].x, values[index].y, values[index].z);
		}

		template <> glm::vec4 Attribs::get(int index) const {
			checkDimension(index, dims[index], 4);
			return values[index];
		}

		void expand(std::vector<int> &dims, std::vector<glm::vec4> &values, int index) {
			if (dims.size() < index+1)
				dims.resize(index+1);
			if (values.size() < index+1)
				values.resize(index+1);
		}

		template <> void Attribs::set(int index, float value) {
			expand(dims, values, index);
			dims[index] = 1;
			values[index].x = value;
		}

		template <> void Attribs::set(int index, glm::vec2 value) {
			expand(dims, values, index);
			dims[index] = 2;
			values[index].x = value.x;
			values[index].y = value.y;
		}

		template <> void Attribs::set(int index, glm::vec3 value) {
			expand(dims, values, index);
			dims[index] = 3;
			values[index].x = value.x;
			values[index].y = value.y;
			values[index].z = value.z;
		}

		template <> void Attribs::set(int index, glm::vec4 value) {
			expand(dims, values, index);
			dims[index] = 4;
			values[index] = value;
		}

		template <typename T> T Uniforms::get(const std::string &name) const {
			return *(T*)values.at(name);
		}

		template <typename T> void Uniforms::set(const std::string &name, T value) {
			auto it = values.find(name);
			if (it != values.end()) {
				delete it->second;
			}
			values[name] = (void*)(new T(value));
		}

		// Implementation of Windows class
		// Creates a window with the given title, size, and samples per pixel.
		
		
		bool Rasterizer::initialize(const std::string &title, int width, int height, int spp){
			bool success = true;
                if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                    printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
                    success = false;
                } else {
                    frameHeight = height;
                    frameWidth = width;
                    displayScale = 1;
                    int screenWidth = frameWidth * displayScale;
                    int screenHeight = frameHeight * displayScale;
                    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
                    if (window == NULL) {
                        printf("Window could not be created! SDL_Error: %s", SDL_GetError());
                        success = false;
                    } else {
                        // windowSurface = SDL_GetWindowSurface(window);
                        // framebuffer = SDL_CreateRGBSurface(0, frameWidth, frameHeight, 32, 0, 0, 0, 0);
						renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
					}
                }
                return success;
		}

		// Returns true if the user has requested to quit the program.
		bool Rasterizer::shouldQuit(){
			SDL_Event e;
        	while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}
			return quit;
		}

		ShaderProgram Rasterizer::createShaderProgram(const VertexShader &vs, const FragmentShader &fs){
			ShaderProgram program;
			program.fs = fs;
			program.vs = vs;
			return program;
		}

		Object Rasterizer::createObject(){
			Object object;
			return object;
		}

		// struct Object {
		// 	using Buffer = std::vector<float>;
		// 	std::vector<Buffer> attributeValues;
		// 	std::vector<int> attributeDims;
		// 	std::vector<glm::ivec3> indices;
		// };


		void setAttribs(Object& object, int attribIndex, int n, int d, const float* data){
			std::cout << "Inside the setAttribs\n";
			
			for (int i = 0; i<n; i++){
				object.attributeValues.push_back({});
				object.attributeDims.push_back({});
			}

			for (int i = 0; i<n; i++){
				for (int j = 0; j<d; j++){
					object.attributeValues[attribIndex+j].push_back(data[i*d + j]);
				}
			}
			
			for (int j = 0; j<d; j++){
				object.attributeDims[attribIndex + j] = 1;
			}
		}


		template <> void Rasterizer::setVertexAttribs(Object &object, int attribIndex, int n, const float* data) {
			setAttribs(object, attribIndex, n, 1, data);
		}

		template <> void Rasterizer::setVertexAttribs(Object &object, int attribIndex, int n, const glm::vec2* data) {
			setAttribs(object, attribIndex, n, 2, (float*)data);
		}

		template <> void Rasterizer::setVertexAttribs(Object &object, int attribIndex, int n, const glm::vec3* data) {
			setAttribs(object, attribIndex, n, 3, (float*)data);
		}

		template <> void Rasterizer::setVertexAttribs(Object &object, int attribIndex, int n, const glm::vec4* data) {
			std::cout << "Inside the setVertexAttribs fxn\n";
			setAttribs(object, attribIndex, n, 4, (float*)data);
		}

		void Rasterizer::setTriangleIndices(Object &object, int n, glm::ivec3* indices){
			object.indices.assign(indices, indices + n);
		}

		void Rasterizer::clear(glm::vec4 color){
			SDL_SetRenderDrawColor(renderer, 255*color[0], 255*color[1], 255*color[2], 255*color[3]);
			SDL_RenderClear(renderer);
			// SDL_FreeSurface(framebuffer);
			// framebuffer = SDL_CreateRGBSurface(0, windowSurface->w, windowSurface->h, 32, color[0], color[1], color[2], color[3]);
		}

		// void Rasterizer::useShaderProgram(const ShaderProgram &program){
			
		// }

		void Rasterizer::show(){
			SDL_RenderPresent(renderer);
			// SDL_BlitScaled(framebuffer, NULL, windowSurface, NULL);
            // SDL_UpdateWindowSurface(window);
		}		

		// Print the contents of the Object
		void Rasterizer::printObject(const Object& object) {
			// Print attributeValues
			std::cout << "attributeValues:" << std::endl;
			for (const auto& buffer : object.attributeValues) {
				for (float value : buffer) {
					std::cout << value << " ";
				}
				std::cout << std::endl;
			}

			// Print attributeDims
			std::cout << "attributeDims:" << std::endl;
			for (int dim : object.attributeDims) {
				std::cout << dim << " ";
			}
			std::cout << std::endl;

			// Print indices
			std::cout << "indices:" << std::endl;
			for (const auto& idx : object.indices) {
				std::cout << "(" << idx.x << ", " << idx.y << ", " << idx.z << ") ";
			}
			std::cout << std::endl;
		}

	}
}