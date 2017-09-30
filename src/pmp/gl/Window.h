//=============================================================================
// Copyright (C) 2011-2017 The pmp-library developers
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//=============================================================================
#pragma once
//=============================================================================

#include <pmp/gl/gl.h>
#include <GLFW/glfw3.h>

//=============================================================================

namespace pmp {

//=============================================================================

//! \addtogroup gl gl
//! @{

//! A window provided by GLFW
class Window
{

public: //------------------------------------------------------ public methods
    //! constructor
    Window(const char* title, int width = 0, int height = 0);

    //! destructor
    virtual ~Window();

    //! main window loop
    int run();

private: //----------------------------- static wrapper functions for callbacks
    static void glfwError(int error, const char* description);
    static void glfwKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void glfwMouse(GLFWwindow* window, int button, int action, int mods);
    static void glfwMotion(GLFWwindow* window, double xpos, double ypos);
    static void glfwScroll(GLFWwindow* window, double xoffset, double yoffset);
    static void glfwResize(GLFWwindow* window, int width, int height);

    static void emscripten_render_loop();

    static Window* m_instance;

protected: //----------------------------------- callbacks as member functions
    //! this function is called when the scene has to be rendered. it
    //! clears the buffers, calls the draw() method, and performs buffer swap
    virtual void display(void) = 0;

    //! this function handles keyboard events
    virtual void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;

    //! this function handles mouse button events
    virtual void mouse(GLFWwindow* window, int button, int action, int mods) = 0;

    //! this function handles mouse motion (passive/active position)
    virtual void motion(GLFWwindow* window, double xpos, double ypos) = 0;

    //! this function handles mouse scroll events
    virtual void scroll(GLFWwindow* window, double xoffset, double yoffset) = 0;

    //! this function is called if the window is resized
    virtual void resize(GLFWwindow* window, int width, int height) = 0;

protected:
    //! GLFW window pointer
    GLFWwindow* m_window;

    //! current viewport dimension
    int m_width, m_height;

    //! highDPI scaling
    int m_scaling;
};

//=============================================================================
//! @}
//=============================================================================
} // namespace pmp
//=============================================================================