package Hello_World;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HelloWorldController {
    String Message="Welcome to my first Spring project!";

    @RequestMapping("/hello")
    public  ModelAndView ShowWelcomeMessage(@RequestParam(value = "name", defaultValue = "World!")String name)
    {
        ModelAndView mv=new ModelAndView("helloworld");
        mv.addObject("message",Message);
        mv.addObject("name",name);
        return mv;
    }
}
