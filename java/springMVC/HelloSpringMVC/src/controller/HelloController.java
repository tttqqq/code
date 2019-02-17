package controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import pojo.User;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


//public class HelloController implements Controller {
//    @Override
//    public ModelAndView handleRequest(javax.servlet.http.HttpServletRequest httpServletRequest, javax.servlet.http.HttpServletResponse httpServletResponse) throws Exception {
//        ModelAndView mav = new ModelAndView("index.jsp");
//        mav.addObject("message", "Hello Spring MVC,my name is chentaoquan");
//        return mav;
//    }
//}


@Controller
public class HelloController{
    @RequestMapping("/hello")
    public ModelAndView handleRequest(javax.servlet.http.HttpServletRequest httpServletRequest, javax.servlet.http.HttpServletResponse httpServletResponse) throws Exception {
        ModelAndView mav = new ModelAndView("index");
        mav.addObject("message", "Hello Spring MVC,my name is chentaoquan,@control");
        return mav;
    }
    @RequestMapping("/test")
    public ModelAndView handleRequest1(javax.servlet.http.HttpServletRequest httpServletRequest, javax.servlet.http.HttpServletResponse httpServletResponse) throws Exception {
        ModelAndView mav = new ModelAndView("test");
//        mav.addObject("message", "Hello Spring MVC,my name is chentaoquan,@control");
        return mav;
    }

    @RequestMapping("/param")
    public ModelAndView getParam(User user) {
        System.out.println(user.getUserName());
        System.out.println(user.getPassword());
        return null;
    }

    @ModelAttribute
    public void model(Model model) {
        model.addAttribute("message", "注解成功");
    }


    @RequestMapping("/value")
    public String handleRequest() {
        return "test2";
    }

    @RequestMapping("/jump")
    public ModelAndView jump() {
        ModelAndView mav = new ModelAndView("redirect:/hello");
        return mav;
    }
}