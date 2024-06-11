#ifndef SceletonMODELDIRECTORFACTORY_H
#define SceletonMODELDIRECTORFACTORY_H

#include <ModelDirectorFactory.h>


class SceletonModelDirectorFactory : public ModelDirectorFactory
{
public:
    virtual std::unique_ptr<ModelDirector> create() override;
};

#endif // SceletonMODELDIRECTORFACTORY_H
