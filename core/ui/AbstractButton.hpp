#ifndef LABYRINTHESCAPE_ABSTRACTBUTTON_HPP
#define LABYRINTHESCAPE_ABSTRACTBUTTON_HPP

#include "Label.hpp"

namespace ui{
    class AbstractButton : public Widget {
    public:
        AbstractButton(Widget* parent = nullptr);
        AbstractButton(const std::string& text, Widget* parent = nullptr);

        void setChecked(bool checked);
        inline bool isChecked() const{
            return m_checked;
        }

        virtual sf::Vector2f getSize() const;

        //TODO : à passer en privée
        virtual void handleEvent(const sf::Event& e) override;

    protected:
        virtual void update() override;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::Color   m_drawColor = { 67, 160, 71 },
                    m_hoverColor = { 46, 125, 50 },
                    m_clickColor = { 66, 66, 66 },
                    m_backgroundColor = { 67, 160, 71 };
        Label m_label;
    private:
        bool m_checked = false;
    };
}

#endif //LABYRINTHESCAPE_ABSTRACTBUTTON_HPP
