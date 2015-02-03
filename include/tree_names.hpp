#ifndef TREE_NAMES_HPP_INCLUDED
#define TREE_NAMES_HPP_INCLUDED
#include <string>
#include <vector>
std::vector<std::string> tree_names()
{
    //c++98 has no nice way to initialize vectors
    std::vector<std::string> t;
    t.push_back("Alder (Alnus)");
    t.push_back("Apple and Pear (Pyrus)");
    t.push_back("Ash (Fraxinus)");
    t.push_back("Aspen and Cottonwood and Poplar (Populus)");
    t.push_back("Basswood (Tilia)");
    t.push_back("Birch (Betula)");
    t.push_back("Buckeye (Aesculus)");
    t.push_back("Buckthorn (Rhamnus)");
    t.push_back("California-laurel (Umbellularia)");
    t.push_back("Catalpa (Catalpa)");
    //t.push_back("Cedar (see \"True Cedar\")");
    t.push_back("Cherry and Plum (Prunus)");
    t.push_back("Chestnut (Castanea)");
    t.push_back("Chinkapin (Castanopsis)");
    t.push_back("Cottonwood and Poplar and Aspen (Populus)");
    t.push_back("Cypress (Cupressus)");
    t.push_back("Dogwood (Cornus)");
    t.push_back("Douglas-fir (Pseudotsuga)");
    t.push_back("Elm (Ulmus)");
    //t.push_back("Fir (see \"True Fir\")");
    t.push_back("Filbert and Hazel (Corylus)");
    t.push_back("Giant Sequoia (Sequoiadendron)");
    t.push_back("Hawthorn (Crataegus)");
    t.push_back("Hazel and Filbert (Corylus)");
    t.push_back("Hemlock (Tsuga)");
    t.push_back("Honeylocust (Gleditsia)");
    t.push_back("Holly (Ilex)");
    //t.push_back("Horsechestnut (see \"Buckeye\")");
    t.push_back("Incense-cedar (Calocedrus)");
    t.push_back("Juniper (Juniperus)");
    t.push_back("Larch (Larix)");
    t.push_back("Locust (Robinia)");
    t.push_back("Madrone (Arbutus)");
    t.push_back("Maple (Acer)");
    t.push_back("Mountain-ash (Sorbus)");
    t.push_back("Mountain-mahogany (Cercocarpus)");
    t.push_back("Oak (Quercus)");
    //t.push_back("Oregon-myrtle (see \"California-laurel\")");
    t.push_back("Pear and Apple (Pyrus)");
    t.push_back("Pine (Pinus)");
    t.push_back("Plum and Cherry (Prunus)");
    t.push_back("Poplar and Aspen and Cottonwood (Populus)");
    t.push_back("Redcedar/Arborvitae (Thuja)");
    t.push_back("Redwood (Sequoia)");
    t.push_back("Russian-olive (Elaeagnus)");
    t.push_back("Spruce (Picea)");
    t.push_back("Sweetgum (Liquidambar)");
    t.push_back("Sycamore (Platanus)");
    t.push_back("Tanoak (Lithocarpus)");
    t.push_back("True Cedar (Cedrus)");
    t.push_back("True Fir (Abies)");
    t.push_back("Walnut (Juglans)");
    t.push_back("White-cedar (Chamaecyparis)");
    return t;
};

#endif // TREE_NAMES_HPP_INCLUDED
