#ifndef __MACHINE__
#define __MACHINE__

#include "Product.h"

/**
 * @brief An interface modeling the smart coffee machine. 
 * It keeps track of the products, the selected one, the sugar level
 * and its state. 
 */
class Machine 
{

public:

    /**
     * @brief Selects the next product after the current one. 
     */
    virtual void selectNextProduct() = 0;

    /**
     * @brief Selects the previous product before the current one.
     */
    virtual void selectPreviousProduct() = 0;

    /**
     * @brief Update the sugar level.
     */
    virtual void updateSugarLevel(const int amount) = 0;

    /**
     * @brief Gets the machine infos of the selected product.
     * @return String containing the product selected and the sugar level. 
     */
    virtual String getInfoSelection() = 0;

};

#endif