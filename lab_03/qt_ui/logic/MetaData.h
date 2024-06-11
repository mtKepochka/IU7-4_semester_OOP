#ifndef METADATA_H
#define METADATA_H

#include <string>
#include <map>
#include <set>


class MetaData
{
public:
    void addObject(int objectId, const std::string& meta);
    void removeObject(int objectId);
    void setObject(int objectId);

    void setCamera(int camera);
    void addCamera(int camera);
    void removeCamera(int camera);

    std::map<int, std::string> &getObjects();
    std::set<int> &getCameras();

    int getSelectedObject();
    int getActiveCamera();
    int getMaxId();
private:
    int nCameras{};
    int activeCamera{};
    int selectedObjectId;

    std::map<int, std::string> objectMap{};
    std::set<int> cameraIds;
    int max_id = 0;
};

#endif // METADATA_H
