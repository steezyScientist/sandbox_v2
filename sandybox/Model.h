#pragma once

#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb_image.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>


struct BoneInfo {
	int id;
	glm::mat4 offset;
};

class Model
{
public:
	Model(const char* path){
		loadModel(path);
	}
	void Draw(Shader shader);
private:
	vector<Mesh> meshes;
	string directory;

	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene);
	
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	GLint TextureFromFile(const char* path, const string& directory);

	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

};