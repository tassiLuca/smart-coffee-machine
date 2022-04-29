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
     * @brief Increment the sugar level by one unit.
     */
    virtual void addSugarLevel() = 0;

    /**
     * @brief Decrease the sugar level by one unit. 
     */
    virtual void decreaseSugarLevel() = 0;

};

#endif