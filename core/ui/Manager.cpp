#include "Manager.hpp"
#include "../Window.hpp"

namespace ui{
    void Manager::addWidget(Widget *widget){
        m_widgets.push_back(widget);
    }

    void Manager::clear(){
        m_widgets.clear();
    }

    void Manager::handleEvent(const sf::Event &e){
        //TODO : récupérer la position de la souris ici pour la diffuser dans les widgets
        for(auto& widget : m_widgets) {
            //Seul les widgets actifs et visibles peuvent répondre aux événements
            if(widget->isEnabled() && widget->isVisible())
                widget->handleEvent(e);
        }
    }

    void Manager::draw() const{
        //::Window::getInstance().setView(::Window::getInstance().getDefaultView());
        for(const auto& widget : m_widgets)
            if(widget->isVisible())
                Window::getInstance().draw(*widget);
    }
}
