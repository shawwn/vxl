#include <emscripten.h>
#include "util.h"
#include "compose.h"
#include "light.h"
// #include <iostream>

EMSCRIPTEN_KEEPALIVE void objectize(
  void *src, void *geometries, unsigned int *geometryIndex,
  unsigned int *blocks, unsigned int *blockTypes, int *dims, unsigned char *transparentVoxels, unsigned char *translucentVoxels, float *faceUvs, float *shift,
  float *positions, float *uvs, unsigned char *ssaos, float *frames, float *objectIndices, unsigned int *indices, unsigned int *objects
) {
  unsigned int positionIndex[NUM_CHUNKS_HEIGHT];
  unsigned int uvIndex[NUM_CHUNKS_HEIGHT];
  unsigned int ssaoIndex[NUM_CHUNKS_HEIGHT];
  unsigned int frameIndex[NUM_CHUNKS_HEIGHT];
  unsigned int objectIndexIndex[NUM_CHUNKS_HEIGHT];
  unsigned int indexIndex[NUM_CHUNKS_HEIGHT];
  unsigned int objectIndex[NUM_CHUNKS_HEIGHT];

  compose(
    src, geometries, geometryIndex,
    blocks, blockTypes, dims, transparentVoxels, translucentVoxels, faceUvs, shift,
    positions, uvs, ssaos, frames, objectIndices, indices, objects,
    positionIndex, uvIndex, ssaoIndex, frameIndex, objectIndexIndex, indexIndex, objectIndex
  );
}

EMSCRIPTEN_KEEPALIVE void lght(
  int ox, int oz, int minX, int maxX, int minY, int maxY, int minZ, int maxZ, unsigned relight,
  float **lavaArray, float **objectLightsArray, float **etherArray, unsigned int **blocksArray, unsigned char **lightsArray
) {
  light(ox, oz, minX, maxX, minY, maxY, minZ, maxZ, (bool)relight, lavaArray, objectLightsArray, etherArray, blocksArray, lightsArray);
}
