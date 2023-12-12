<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <link rel="stylesheet" type="text/css" href="style.css" />
            </head>
            <body>
                <h1>College Information</h1>
                <xsl:apply-templates select="document/college" />
                <h2>Students</h2>
                <ul>
                    <xsl:apply-templates select="document/students/student" />
                </ul>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="college">
        <p class="college-info">
            <xsl:value-of select="." />
        </p>
    </xsl:template>

    <xsl:template match="student">
        <li>
            <h3>
                <xsl:value-of select="name/firstname" />
                <xsl:value-of select="name/lastname" />
            </h3>
            <p>Roll: <xsl:value-of select="roll" /></p>
            <p>Program: <xsl:value-of select="program" /></p>
            <p>Branch: <xsl:value-of select="branch" /></p>
            <h4>Projects</h4>
            <ul>
                <xsl:apply-templates select="projects/project" />
            </ul>
        </li>
    </xsl:template>

    <xsl:template match="project">
        <li>
            <p>Project ID: <xsl:value-of select="projectID" /></p>
            <p>Subject: <xsl:value-of select="subject" /></p>
            <p>Assign Date: <xsl:value-of select="assigndate" /></p>
            <p>Deadline: <xsl:value-of select="deadline" /></p>
            <p>Topic: <xsl:value-of select="topic" /></p>
        </li>
    </xsl:template>
</xsl:stylesheet>