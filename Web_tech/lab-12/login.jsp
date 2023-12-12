<%@ page import="java.util.*" %>
    <% String username=request.getParameter("u_name"); if (username !=null && username.equals("admin")) {
        session.setAttribute("u_name", username); response.sendRedirect("home.jsp"); } else { out.print("Invalid
        Username"); } %>
        <script>
            // JavaScript code to update the content dynamically
            var username = '<%= session.getAttribute("u_name") %>';
            document.cookie = "username=" + username;
        </script>