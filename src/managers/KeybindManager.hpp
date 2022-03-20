#pragma once

#include "../defines.hpp"
#include <deque>
#include "../Compositor.hpp"

struct SKeybind {
    std::string       key = 0;
    uint32_t          modmask = 0;
    std::string       handler = "";
    std::string       arg = "";
};

class CKeybindManager {
public:
    bool                handleKeybinds(const uint32_t&, const xkb_keysym_t&);
    void                addKeybind(SKeybind);
    uint32_t            stringToModMask(std::string);
    void                clearKeybinds();

private:
    std::deque<SKeybind> m_dKeybinds;


    // -------------- Dispatchers -------------- //
    void                killActive(std::string);
    void                spawn(std::string);
    void                toggleActiveFloating(std::string);

};

inline std::unique_ptr<CKeybindManager> g_pKeybindManager;