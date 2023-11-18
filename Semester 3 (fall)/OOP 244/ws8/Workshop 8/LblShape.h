#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
        char* m_label{ NULL };
    protected:
        const char* label() const;
    public:
        LblShape() = default;
        LblShape(const char* label);
        virtual ~LblShape() override;
        LblShape(const LblShape& other) = delete;
        LblShape& operator=(const LblShape& other) = delete;
        void getSpecs(std::istream& is) override;
    };
}

#endif